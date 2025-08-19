# ESP-Firebase-Web-App - LÊ NGỌC TUẤN

Đề tài 3: Đọc cảm biến ánh sáng để điều khiển bật tắt led (cập nhật giá trị lên Firebase),
điều khiển led bằng Firebase web

# A. Công việc đã làm 

## 1. Video demo: https://youtube.com/shorts/ilBtpRJlL7w?feature=share
## 2. Sơ đồ khối và nguyên lý hoạt động
### a. Sơ đồ khối
![alt](sodokhoi.png)
### b. Nguyên lý hoạt động
- Module cảm biến ánh sáng: Chuyển cường độ ánh sáng thành tín hiệu điện tương ứng dựa 
trên hiệu ứng quang điện, quang dẫn hoặc sự tháy đổi điện trở
- Esp32: Kết nối với Wifi để nhận và gửi dữ liệu từ esp lên firebase và ngược lại
- Màn Oled: hiện thị các thông tin cơ bản mà mình muốn
- Led: nhận tín hiệu từ esp và tín hiệu từ module cảm biến ánh sáng làm điều kiện bật và tắt led

## 3. Sơ đồ chân 
ESP32	| Cảm biến ánh sáng | OLED  |  LED 	| 
--------|-------------------|-------|-------|
G21		|		D0			|		|		|
GND		|		GND			|	GND	|	-	|
3v3		|		VCC			|	VDD	|		|
G18		|					|	SCL	|		|
G23		|					|	SDA	|		|
G4		|					|	RST	|		|
G2		|					|	DC	|		|
G5		|					|	CS	|		|
3v3		|					|	BLK	|		|
G26		|					|		|	+	|

## 4. Tính năng
- Đọc giá trị cảm biến ánh sáng
- Điều khiển led bằng cảm biến ánh sáng
- Gửi dữ liệu từ esp32 lên Firebase
- Hiện thị lên màn Oled
- Điều khiển led bằng Realtime Database
- Điều khiển led bằng cả firebase và cảm biến ánh sáng 

## 5. Code
### a. Kết nối Firebase với esp
- File.h	
	
		#ifndef firebase_H
		#define firebase_H
		#include <Arduino.h>
		#include <WiFi.h>
		#include <FirebaseESP32.h> // library of firebaseESP32

		// khởi tạo biến toàn cục cho firebase
		extern FirebaseData fbData;
		extern FirebaseAuth auth;
		extern FirebaseConfig config;

		// khởi tạo biến cho Wifi
		extern const char* ssid;
		extern const char* password;

		// khởi tạo biến
		extern String data5base;
		extern int value_of_firebase;
		extern int check1;
		// biến thay đổi data
		extern const char* name_int;
		extern const char* name_day;
		extern const char* value_led;
		extern const char* state;

		class firebase {
		  public:
		  static void wifi_connection(); // kết nối wifi
		  static void connection_firebase(); // kết nối vơi firebase
		  static void control_led(); // điều khiển led từ firebase
		  static void get_to_firebase_from_esp(const int& value_of_thing); // hàm đọc và gửi giá trị từ esp lên firebase
		  static void read_firebase(); // hàm đọc data trên firebase
		};
		#endif 
- File.cpp
			
			/*
			File: Kết nối Esp32 với firebase
			Chú ý: Khi lập trình thì khởi tạo hàm này trong file "firebase_esp.cpp"
			Mục đích: Kết nối Esp32 với Wifi và Firebase và sử dụng các hàm khác
			*/

			#include <Arduino.h>
			#include "firebase.h" // thư viện tự khởi tạo để quản lý các hàm liên quan đến firebase
			#include <FirebaseESP32.h> // thư viên của firebase kết nối esp32
			#include <WiFi.h> // thư viện kết nối wifi
			#include <pin.h> // thư viện để khai báo các chân kết nối
			#include <tft.h> // thư viện để hiện thị lên oled
			#include <light.h> // thư viện để điều khiển led
			
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
			
			/*
			  File: Tạo các hàm liên quan đến firebase gồm đọc data từ firebase, điều khiển led từ firebase, đẩy data từ esp32 lên firebase
			  Mục đích: Quản lý các hàm liên quan đến firebase
			  Chú ý: Khi lập trình thì khởi tạo hàm này trong file "firebase_esp.cpp"
			*/


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



