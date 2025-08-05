/* Wifi_SoftAP.hpp

WifiのSetupをするための関数が入っています

Wifi名とPasswordはこのファイルから変えてください
*/
#ifndef WIFI_SOFTAP_HPP
#define WIFI_SOFTAP_HPP

#include <WiFi.h>

namespace WifiSoftAP{

  // UDPオブジェクト
  WiFiUDP udp;
  
  // 送信先の設定
  IPAddress broadcastIP(192, 168, 30, 255);  // ブロードキャスト
  int udpPort = 1234;

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
    
    // UDP通信を開始
    udp.begin(udpPort);
  }

  //SoftAPの状態を表示
  void PrintStatus(){

    Serial.println("SoftAP started");
    Serial.print("AP IP address: ");
    Serial.println(WiFi.softAPIP());
    Serial.println("UDP Debug Server started on port 1234");
    Serial.println("Listening tools:");
    Serial.println("  Windows: nc -u 192.168.30.3 1234");
    Serial.println("  Python: socket.socket(socket.AF_INET, socket.SOCK_DGRAM)");
  }
  
  // 任意の数のデータを送信（ラベルなし/CSV保存可能）
  template<typename... Args>
  void SendData(Args... args) {
    udp.beginPacket(broadcastIP, udpPort);
    
    // 引数をString配列に変換
    uint8_t length = sizeof...(args);
    String ary[] = { String(args)... };
    
    // for文でカンマ区切りで送信
    for(uint8_t i = 0; i < length; i++) {
      if(i > 0) udp.print(",");  // 最初以外はカンマを付ける
      udp.print(ary[i]);
    }
    
    udp.println();  // 最後に改行
    udp.endPacket();
  }
  
  // 任意の数のデータを送信（ラベル付き）
  template<typename... Args>
  void SendData(const char* label, Args... args) {
    udp.beginPacket(broadcastIP, udpPort);
    udp.print(label);
    udp.print(":");
    
    // 引数をString配列に変換
    uint8_t length = sizeof...(args);
    String ary[] = { String(args)... };
    
    // for文でカンマ区切りで送信
    for(uint8_t i = 0; i < length; i++) {
      if(i > 0) udp.print(",");  // 最初以外はカンマを付ける
      udp.print(ary[i]);
    }
    
    udp.println();  // 最後に改行
    udp.endPacket();
  }
}

#endif // WIFI_SOFTAP_HPP
