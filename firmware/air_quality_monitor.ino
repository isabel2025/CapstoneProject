#include <Wire.h>
#include "Adafruit_SHT31.h"
#include "Adafruit_CCS811.h"
#include <sps30.h>

// Status and alert outputs
#define LED_GREEN 15
#define LED_RED 16
#define BUZZER 13

Adafruit_SHT31 sht31 = Adafruit_SHT31();
Adafruit_CCS811 ccs;

bool enableHeater = false;
uint8_t loopCnt = 0;

void setup() {
  Serial.begin(9600);
  delay(2000);

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Wire.begin(21, 22);

  if (!sht31.begin(0x44)) {
    Serial.println("SHT31 not found.");
    alertError();
  }

  if (!ccs.begin()) {
    Serial.println("CCS811 not found.");
    alertError();
  }
  while (!ccs.available());

  sensirion_i2c_init();
  if (sps30_probe() != 0) {
    Serial.println("SPS30 not found.");
    alertError();
  }

  sps30_set_fan_auto_cleaning_interval_days(4);
  sps30_start_measurement();

  beep(1);
}

void loop() {
  // SHT31: temperature and humidity
  float temp = sht31.readTemperature();
  float hum = sht31.readHumidity();

  if (!isnan(temp) && !isnan(hum)) {
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print(" C, Humidity: ");
    Serial.println(hum);
  }

  if (++loopCnt >= 30) {
    enableHeater = !enableHeater;
    sht31.heater(enableHeater);
    loopCnt = 0;
  }

  // CCS811: eCO2 and TVOC
  bool badAir = false;
  if (ccs.available() && !ccs.readData()) {
    uint16_t co2 = ccs.geteCO2();
    uint16_t tvoc = ccs.getTVOC();

    Serial.print("eCO2: ");
    Serial.print(co2);
    Serial.print(" ppm, TVOC: ");
    Serial.println(tvoc);

    if (co2 > 1000 || tvoc > 400) {
      badAir = true;
    }
  }

  // SPS30: particulate matter
  struct sps30_measurement m;
  uint16_t data_ready;

  if (sps30_read_data_ready(&data_ready) >= 0 && data_ready) {
    if (sps30_read_measurement(&m) >= 0) {
      Serial.print("PM2.5: ");
      Serial.print(m.mc_2p5);
      Serial.print(" ug/m3, PM10: ");
      Serial.println(m.mc_10p0);

      if (m.mc_2p5 > 35 || m.mc_10p0 > 50) {
        badAir = true;
      }
    }
  }

  // Local alert logic
  if (badAir) {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
    beep(3);
  } else {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
  }

  delay(1000);
}

void beep(int count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);
    delay(200);
  }
}

void alertError() {
  while (1) {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(100);
    digitalWrite(BUZZER, LOW);
    delay(100);
  }
}
