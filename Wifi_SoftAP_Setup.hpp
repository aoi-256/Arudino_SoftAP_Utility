/* Wifi_SoftAP_Setup.hpp

WifiのSetupをするための関数が入っています

Wifi名とPasswordはこのファイルから変えてください
*/
#ifndef WIFI_SOFTAP_SETUP_HPP
#define WIFI_SOFTAP_SETUP_HPP

#include <WiFi.h>

namespace WifiSoftAP{

  // ssid（WiFiのネットワーク名）
  const char *ssid = "TEST_WIFI";

  // pass（WiFiのパスワード。NULLにするとパスワードなしになる）
  const char *pass = nullptr;  // パスワードなしの場合

  // ip（このデバイスが持つIPアドレス）
  const IPAddress ip(192, 168, 30, 3);

  // subnet（サブネットマスク。ネットワークの範囲を指定）
  const IPAddress subnet(255, 255, 255, 0);

  //設定をもとにSoftAPを初期化
  void Setup(){

    WiFi.softAPConfig(ip, ip, subnet);
    WiFi.softAP(ssid, pass, 1, 0, 4);  // 最大4台まで接続可能
  }

  //SoftAPの状態を表示
  void PrintStatus(){

    Serial.println("SoftAP started");
    Serial.print("AP IP address: ");
    Serial.println(WiFi.softAPIP());
  }
}

#endif // WIFI_SOFTAP_SETUP_HPP
