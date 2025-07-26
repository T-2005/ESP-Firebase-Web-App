/*
    File: Khởi tạo các hàm khởi tạo màn hiện thị Oled, hiển thị trạng thái của thiết bị, hàm xóa trên oled
    Mục đích: Quản lý các hàm liên quan đến oled
    Chú ý: Khi lập trình thì khởi tạo hàm này trong file "tft.cpp"
*/

#include "tft.h"
#include "light.h"
#include "light.h"
#include <pin.h>


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void display ::hien_thi() {
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(0);
  tft.fillScreen(ST7735_BLACK);
}

void display ::state_of_device(const int& value) {

  
  tft.setCursor(0, 90); // SET điểm bắt đầu viết chữ tọa độ X, Y
  if (value == 1) {  
   
    tft.print("Chao buoi toi!");
  } 
  else 
  {
    
    tft.print("Chao buoi sang!");
  }
}

void display::clear()
{
  tft.fillRect(0, 90, 150, 80, ST7735_BLACK);  // tft.fillRect(x1, y1, x2, y2, ST77XX_COLOR);   
}