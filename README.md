# Arudino_SoftAP_Utility

wifi.hでsoftAPを簡単に設定するためのコードです

wifi上で任意のデータを送れるようにしました

## 使い方

### 1. ファイルのダウンロード

この2つのファイルをArudinoIDEでマイコンに書き込み

```
main.ino
Wifi_SoftAP.hpp
```
このファイルをPCにダウンロード(最新のpythonをインストール）

```
Receiver.py
```

### 2. 送りたいデータを設定

送信したいデータを選択する

- 第1引数の"Label"はありなしが選べます

- 変数型はTemplateを使用しているので気にしないで大丈夫です

```cpp
  // サンプルのセンサーデータ
  int data1 = random(-1000, 1000);
  int data2 = random(-1000, 1000);
  int data3 = random(-1000, 1000);

  // データ送信
  WifiSoftAP::SendData("SensorData", data1, data2, data3);
```

### 3. PC側で受信用意をする

Wifiのタブを開いて、デフォルトで```Test_Wifi```があるはずなので、そこに接続

1でダウンロードしたpythonコードを実行するとデータが取得できる
