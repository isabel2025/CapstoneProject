import 'package:flutter/material.dart';
import 'models/sensor_data.dart';
import 'services/api_service.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'ESP32 Sensor Monitor',
      theme: ThemeData(primarySwatch: Colors.blue),
      home: SensorDashboard(),
    );
  }
}

class SensorDashboard extends StatefulWidget {
  @override
  _SensorDashboardState createState() => _SensorDashboardState();
}

class _SensorDashboardState extends State<SensorDashboard> {
  late Future<List<SensorData>> _futureData;

  @override
  void initState() {
    super.initState();
    _futureData = ApiService.fetchSensorData();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text("Live Sensor Readings")),
      body: FutureBuilder<List<SensorData>>(
        future: _futureData,
        builder: (context, snapshot) {
          if (snapshot.hasData) {
            final data = snapshot.data!;
            return ListView.builder(
              itemCount: data.length,
              itemBuilder: (context, index) {
                final d = data[index];
                return ListTile(
                  title: Text("Temp: ${d.temperature} °C | Humidity: ${d.humidity} %"),
                  subtitle: Text("Alcohol: ${d.alcohol}% • ${d.timestamp}"),
                );
              },
            );
          } else if (snapshot.hasError) {
            return Center(child: Text("Error: ${snapshot.error}"));
          } else {
            return Center(child: CircularProgressIndicator());
          }
        },
      ),
    );
  }
}
