# Firmware

`air_quality_monitor.ino` contains the ESP32 sensor and alert logic used for the air-quality monitor.

It includes:

- SHT31 temperature and humidity sensing over I2C
- CCS811 eCO2 and TVOC sensing over I2C
- SPS30 particulate-matter sensing
- green/red status LEDs
- buzzer alerts for poor air quality and sensor errors
