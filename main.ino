#include "Wifi_SoftAP.hpp"

void setup() {

  // シリアル通信初期化
  Serial.begin(115200);
  
  //Wifi_SoftAPの初期化
  WifiSoftAP::Setup();
  WifiSoftAP::PrintStatus();
}

void loop() {
  // === 可変引数テンプレート版SendDataのデモ ===
  
  // サンプルのセンサーデータ
  int data1 = random(-1000, 1000);
  int data2 = random(-1000, 1000);
  int data3 = random(-1000, 1000);

  // データ送信
  WifiSoftAP::SendData("SensorData", data1, data2, data3);
  delay(100);

  // === 新しいSendData関数のデモ ===
  
  // // 1. 単一データ送信
  // WifiSoftAP::SendData(temperature);
  // delay(100);

  // // 2. 2つのデータ送信
  // WifiSoftAP::SendData(temperature, humidity);
  // delay(100);

  // // 3. 3つのデータ送信（CSV形式）
  // WifiSoftAP::SendData(temperature, humidity, pressure);
  // delay(100);

  // // 4. 4つのデータ送信
  // WifiSoftAP::SendData(sensorId, temperature, humidity, pressure);
  // delay(100);

  // // 5. 5つのデータ送信（無制限対応のデモ）
  // WifiSoftAP::SendData(sensorId, temperature, humidity, pressure, timestamp);
  // delay(100);

  // // 6. ラベル付き送信（デバッグ用）
  // WifiSoftAP::SendData("sensor", temperature, humidity, pressure);
  // delay(100);

  // // 7. 混合型のデータ送信
  // bool isActive = (temperature > 25.0);
  // WifiSoftAP::SendData("status", sensorId, temperature, isActive, timestamp);
  // delay(100);

  // // 8. 異なる型の大量データ送信（デモ）
  // WifiSoftAP::SendData("multi", 1, 2.5f, 3u, 4L, true, "test", 7.89);
  
  // Serial.println("--- Data sent via WiFi UDP ---");
  // delay(3000);  // 3秒間隔で送信
}
