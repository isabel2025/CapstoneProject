# Firmware

`air_quality_monitor.ino` contains the sensor-reading and local alert logic from the air-quality monitoring project.

It includes:

- SHT31 temperature and humidity sensing over I2C
- CCS811 eCO2 and TVOC sensing over I2C
- SPS30 particulate-matter sensing
- green/red status LEDs
- buzzer alerts for poor air quality and sensor errors

The full capstone system also included Wi-Fi data transmission to the PHP/MySQL backend. That networking logic is not part of this firmware file.
