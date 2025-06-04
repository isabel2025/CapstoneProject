# Air Quality Index (AQI) Prediction Using Random Forest

This repository implements a machine learning model for predicting the **Air Quality Index (AQI)** using environmental sensor data. 

---

## 📊 Project Overview

This project demonstrates how a **Random Forest Regressor** can be used to model the AQI based on key features like:

- **PM2.5** (Particulate Matter)
- **CO₂** (Carbon Dioxide)
- **VOCs** (Volatile Organic Compounds)
- **Temperature**
- **Humidity**

A dataset of 5,000 entries is used to simulate real-world data collected at 5-second intervals.

---

## 📁 Repository Contents

- `aqi_model.py` – Main script that loads the dataset, trains the model, and visualizes predictions.
- `aqi_dataset.csv` – Simulated dataset (5000 samples, 5 features + AQI).
- `aqi_dataset.xlsx` – Same dataset in Excel format.
- `aqi_prediction_plot.png` – Visualization of model predictions.
- `requirements.txt` – Python dependencies.
- `README.md` – Project documentation.

---

## 📈 Model Performance

The model achieves:

- **R² Score**: ~0.98  
- **Mean Squared Error**: ~104.64

These metrics indicate the model can explain over 98% of the variance in AQI values based on the given features.

---

## 🛠️ How to Run

1. **Install the required packages**:
   ```bash
   pip install -r requirements.txt
