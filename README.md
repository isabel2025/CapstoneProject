# Solar-Powered IoT Air Quality Monitoring System

A Computer Engineering capstone project by **Isabel Prempeh Herraiz** that combines embedded systems, environmental sensing, data storage, mobile development, and machine learning to monitor air quality and explore AQI prediction.

**Supervisor:** Kofi Adu-Labi  
**Institution:** Ashesi University  
**Year:** 2025

## Project Overview

The system was designed as an end-to-end air-quality monitoring prototype. Environmental sensors connected to an ESP32 captured measurements including:

- PM2.5
- CO₂
- VOCs
- Temperature
- Humidity

The prototype was powered using a solar-based setup, stored readings in a MySQL database, and used a Flutter mobile application to display live and historical data. A Random Forest regression model was also developed to predict Air Quality Index (AQI) values.

## System Architecture

```text
Environmental Sensors
        ↓
      ESP32
        ↓
 Data / Backend Layer
        ↓
   MySQL Database
      ↙       ↘
Flutter App   ML Model
                  ↓
             AQI Prediction
```

## Machine Learning

The repository currently includes a Jupyter notebook that:

1. Loads the AQI dataset.
2. Separates environmental measurements from the AQI target.
3. Splits the data into training and test sets.
4. Trains a `RandomForestRegressor`.
5. Evaluates the model using Mean Squared Error and R².
6. Plots predicted AQI values against actual values.

### Model inputs

- PM2.5
- CO₂
- VOCs
- Temperature
- Humidity

### Target

- AQI

> **Data note:** The CSV currently included in this repository is retained as the dataset used with the notebook. Its provenance should be verified before it is described as field-collected sensor data.

## Hardware & Software

### Hardware

- ESP32 microcontroller
- Environmental sensors
- Custom PCB
- Solar-powered prototype

### Software

- Python
- Pandas
- NumPy
- Scikit-learn
- Jupyter Notebook
- Flutter
- MySQL

## Current Repository Contents

| File | Purpose |
| --- | --- |
| `CapstoneCode.ipynb` | Random Forest model training and evaluation |
| `aqi_dataset.csv` | Dataset used by the ML notebook |
| `Demo.mp4` | Project demonstration video |
| `IsabelPrempehCapstone_KofiAdu-Labi.pdf` | Final capstone report |

The original project also included embedded, backend/database, and Flutter components. Those source files are not currently present in this repository and should be added once recovered.

## How to Run the ML Notebook

1. Clone the repository.
2. Install the required Python packages:

```bash
pip install numpy pandas scikit-learn matplotlib seaborn jupyter
```

3. Open the notebook:

```bash
jupyter notebook CapstoneCode.ipynb
```

4. Run the cells in order.

## Why This Project Matters

Air-quality monitoring systems can help make environmental conditions easier to measure and understand. This project explores how low-cost embedded hardware, connected software, and machine learning can be combined into one practical monitoring system.

## Next Improvements

- Restore and document the ESP32 firmware.
- Add the Flutter application source code.
- Add backend/database setup files.
- Add PCB design files and an architecture diagram.
- Verify and document the origin of the ML dataset.
- Re-run model evaluation on verified field data if available.
- Containerize the backend and data services.
- Deploy a live dashboard or hosted demo.
