# PHP / MySQL backend prototype

This was used during development to test the data path from the ESP32 to MySQL.

The example:

- receives temperature and humidity over HTTP
- validates the values
- stores readings in MySQL
- returns the latest readings as JSON for the dashboard/app

The final capstone system expanded this flow to the full air-quality sensor set.
