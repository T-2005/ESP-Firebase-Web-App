
#include "tft.h"
#include "light.h"
#include "pin.h"

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void display ::hien_thi() {
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(0);
  tft.fillScreen(ST7735_BLACK);
}

void display ::state_of_device(const int& value) {

  tft.setCursor(0, 90); // set điểm bắt đầu ghi 
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
  tft.fillRect(0, 90, 150, 80, ST7735_BLACK);    // tft.fillRect(x1, y1, x2, y2, ST77XX_COLOR);
}