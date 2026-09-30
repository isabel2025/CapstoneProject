<?php
$servername = "localhost";
$username = "root";
$password = "";
$database = "esp_data";

$conn = new mysqli($servername, $username, $password, $database);
if ($conn->connect_error) {
    http_response_code(500);
    exit('Database connection failed');
}

$sql = "SELECT id, temperature, humidity, timestamp
        FROM sensor_readings
        ORDER BY timestamp DESC
        LIMIT 10";
$result = $conn->query($sql);

$data = [];
while ($row = $result->fetch_assoc()) {
    $data[] = $row;
}

header('Content-Type: application/json');
echo json_encode(array_reverse($data));
$conn->close();
?>
