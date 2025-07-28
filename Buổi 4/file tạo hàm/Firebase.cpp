/*
    File: Kết nối Esp32 với firebase
    Chú ý: Khi lập trình thì khởi tạo hàm này trong file "firebase_esp.cpp"
    Mục đích: Kết nối Esp32 với Wifi và Firebase và sử dụng các hàm khác
*/


#include <Arduino.h>
#include <FirebaseESP32.h> // library of firebaseESP32


FirebaseData fbData; // khai báo biến fbData để lấy dữ liệu từ firebase
FirebaseAuth auth; // khai báo biến auth để xác thực người dùng
FirebaseConfig config; // khai báo biến config để cấu hình firebase

// lấy link theo hướng dẫn tại: https://github.com/T-2005/ESP-Firebase-Web-App/tree/main/Bu%E1%BB%95i%202
#define Firebase_Host  "fir-with-sensor-light-default-rtdb.firebaseio.com/"
#define Firebase_Auth  "Ol77jhIXlTxjaAjCjDP9fRlDUPAGs7E46iGnknGe"
void firebase :: firebase_connection()
{
  config.host = Firebase_Host ; // link realtime database
  config.signer.tokens.legacy_token = Firebase_Auth; // xác thực người dùng
  Firebase.begin(&config, &auth); // Khởi tạo firebase với config và auth
  Firebase.reconnectWiFi(true); // tự động kết nối lại wifi khi mất kết nối
}