import 'dart:convert';
import 'package:http/http.dart' as http;
import '../models/sensor_data.dart';

class ApiService {
  static const String baseUrl = "http://YOUR_SERVER_IP/view_data.php";

  static Future<List<SensorData>> fetchSensorData() async {
    final response = await http.get(Uri.parse(baseUrl));

    if (response.statusCode == 200) {
      List<dynamic> data = json.decode(response.body);
      return data.map((json) => SensorData.fromJson(json)).toList();
    } else {
      throw Exception("Failed to load data");
    }
  }
}
