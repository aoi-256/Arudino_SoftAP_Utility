#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Arduino WiFi UDP Debug Data Receiver
ESP32から送信されるUDPデータを受信して表示するプログラム

使用方法:
1. ESP32のWiFiアクセスポイント "TEST_WIFI" に接続
2. このスクリプトを実行
3. ESP32から送信されるデータをリアルタイムで表示
"""

import socket
import time
import sys
from datetime import datetime

# UDP受信設定
UDP_IP = "0.0.0.0"      # すべてのIPアドレスで受信
UDP_PORT = 1234         # ESP32側と同じポート番号
BUFFER_SIZE = 1024      # 受信バッファサイズ

def main():
    print("=== Arduino WiFi UDP Debug Data Receiver ===")
    print(f"Listening on port {UDP_PORT}")
    print("Waiting for data from ESP32...")
    print("Press Ctrl+C to stop")
    print("-" * 50)
    
    # UDPソケットを作成
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.bind((UDP_IP, UDP_PORT))
        print(f"✓ UDP socket bound to {UDP_IP}:{UDP_PORT}")
    except Exception as e:
        print(f"❌ Error creating socket: {e}")
        sys.exit(1)
    
    try:
        while True:
            # データを受信
            data, addr = sock.recvfrom(BUFFER_SIZE)
            packet_count += 1
           
            # 受信データを文字列に変換
            try:
                message = data.decode('utf-8').strip()
            except UnicodeDecodeError:
                message = data.hex()  # バイナリデータの場合は16進数で表示
            
            # データを表示（6桁分のスペースで右寄せ、長い場合はそのまま表示）
            if len(message) <= 6:
                print(f"{message:>6}")
            else:
                print(message)
                
    except KeyboardInterrupt:
        print(f"\n\n=== Session Summary ===")
        print("Program terminated by user")
    except Exception as e:
        print(f"❌ Error: {e}")
    finally:
        sock.close()
        print("✓ Socket closed")

if __name__ == "__main__":
    main()
