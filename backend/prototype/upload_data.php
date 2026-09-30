<?php
$servername = "localhost";
$username = "root";
$password = "";
$database = "esp_data";

if (!isset($_GET['temp'], $_GET['humidity'])) {
    http_response_code(400);
    exit('Missing temp or humidity');
}

$temp = filter_var($_GET['temp'], FILTER_VALIDATE_FLOAT);
$humidity = filter_var($_GET['humidity'], FILTER_VALIDATE_FLOAT);

if ($temp === false || $humidity === false) {
    http_response_code(400);
    exit('Invalid sensor values');
}

$conn = new mysqli($servername, $username, $password, $database);
if ($conn->connect_error) {
    http_response_code(500);
    exit('Database connection failed');
}

$stmt = $conn->prepare("INSERT INTO sensor_readings (temperature, humidity) VALUES (?, ?)");
$stmt->bind_param("dd", $temp, $humidity);

if ($stmt->execute()) {
    echo "Data inserted successfully";
} else {
    http_response_code(500);
    echo "Insert failed";
}

$stmt->close();
$conn->close();
?>
