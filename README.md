# Arudino_SoftAP_Utility

wifi.hでsoftAPを簡単に設定するためのコードです

wifi上で任意のデータを送れるようにしました

## 使い方

### 1. パスワードとネットワーク名の設定

Wifi_SoftAP_Setup.hpp内のこの部分を変更してください
```cpp
  // ssid（WiFiのネットワーク名）
  const char *ssid = "TEST_WIFI";

  // pass（WiFiのパスワード。NULLにするとパスワードなしになる）
  const char *pass = nullptr;  // パスワードなしの場合
```

### 2. 実際の使用例

```cpp
void setup(){

  //Wifi_SoftAPの初期化
  WifiSoftAP::Setup();
  WifiSoftAP::PrintStatus();
}

void loop(){

  float data[3] = {1.0, 2.0, 3.0};

  //データのみ(csv保存用）
  WifiSoftAP::SendData(data[0], data[1], data[2]);

  //ラベル付き（シリアルポートでの閲覧用）
WifiSoftAP::SendData("data_name", data[0], data[1], data[2]);
}
```
