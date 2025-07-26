/*
    File: Khai báo chân cho các thiết bị kết nối với esp32
    Mục đích: Khởi tạo các chân kết nối của esp32
    Lưu ý: Các chân kết nối của esp32 có thể thay đổi tùy vào từng board mạch
*/

#include <pin.h>  
#include<Arduino.h>

int D0 = 21; // chân tín hiệu của module cảm biến ánh sáng
int Led = 26; // chân của led
int TFT_CS = 5;
int TFT_RST = 4;
int TFT_DC = 2;

void pin :: init()
{
  pinMode(Led, OUTPUT);
  pinMode(D0, INPUT);
}