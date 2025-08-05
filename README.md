# Arudino_SoftAP_Utility

wifi.hでsoftAPを簡単に設定するためのコードです。

こんなのなくても簡単に書けます

基本的な設定を書いています。

複雑な実装をしたい場合はご自身で調べてください

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
void Setup(){

  //Wifi_SoftAPの初期化
  WifiSoftAP::Setup();
  WifiSoftAP::PrintStatus();
}
```
