/*
  File: Tạo các hàm liên quan đến firebase gồm đọc data từ firebase, điều khiển led từ firebase, đẩy data từ esp32 lên firebase
  Mục đích: Quản lý các hàm liên quan đến firebase
  Chú ý: Khi lập trình thì khởi tạo hàm này trong file "firebase_esp.cpp"
*/

#include "firebase.h" // thư viện tự khởi tạo để quản lý các hàm liên quan đến firebase

#include <pin.h> // thư viện để khai báo các chân kết nối
#include <tft.h> // thư viện để hiện thị lên oled
#include <light.h> // thư viện để điều khiển led

// khai báo tên biến trong firebase
const char* name_int = "/value_of_sensor_light"; 
const char* name_day = "/day";
const char* value_led = "test/control";
const char* state = "test/state";
// khai báo tên biến trong firebase

String data5base; // biến dùng để lưu trữ dữ liệu từ firebase dạng chuỗi
int value_of_firebase; // Biến dùng để lưu trữ dữ liệu từ firebase dạng số nguyên 
int check1 = 0; // biến dùng để kiểm tra trạng thái của led dùng để xóa kí tự trên oled

void firebase :: read_firebase() // đocj dữ liệu từ firebase
{
    Firebase.getInt(fbData, value_led); // lấy dữ liệu từ firebase dạng số nguyên
    value_of_firebase = fbData.intData(); 
    Firebase.getString(fbData, state); // lấy dữ liệu từ firebase dạng chuỗi
    data5base = fbData.stringData(); 
}

void firebase :: control_led() // điều khiển led từ firebase
 { 
    light :: check_and_clear_oled(value_of_firebase, check1); // hàm xóa kí tự trên oled
    display::day(value_of_firebase); // hiển thị lên oled  
    light :: on_off_led(value_of_firebase); // bất tắt led theo firebase
 }

void firebase :: get_to_firebase_from_esp(const int& value_of_thing) // đẩy data từ esp32 lên firebase
{
   Firebase.setInt(fbData, name_int, value_of_thing); // đẩy dữ liệu từ esp32 lên firebase dạng số nguyên
   if(value_of_thing == 0) Firebase.setString(fbData,name_day, "Chao buoi sang!");
   else Firebase.setString(fbData,name_day, "Chao buoi toi!");   
   Serial.println("Push data to /esp done !");
   delay(500);
 }