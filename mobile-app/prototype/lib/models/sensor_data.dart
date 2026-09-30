class SensorData {
  final int id;
  final double temperature;
  final double humidity;
  final double alcohol;
  final String timestamp;

  SensorData({
    required this.id,
    required this.temperature,
    required this.humidity,
    required this.alcohol,
    required this.timestamp,
  });

  factory SensorData.fromJson(Map<String, dynamic> json) {
    return SensorData(
      id: int.parse(json['id']),
      temperature: double.parse(json['temperature']),
      humidity: double.parse(json['humidity']),
      alcohol: double.parse(json['alcohol']),
      timestamp: json['timestamp'],
    );
  }
}
