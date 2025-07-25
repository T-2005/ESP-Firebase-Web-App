

#include "tft.h"
#include "light.h"
#include "light.h"
int TFT_CS = 5;
int TFT_RST = 4;
int TFT_DC = 2;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void display ::hien_thi() {
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(0);
  tft.fillScreen(ST7735_BLACK);
}
void display ::day(const int& check) {

  light::start_led();
  tft.setCursor(0, 90);
  if (check == 1) {  
   
    tft.print("Chao buoi toi!");
  } 
  else 
  {
    
    tft.print("Chao buoi sang!");
  }
}

void display::clear()
{
  tft.fillRect(0, 90, 150, 80, ST7735_BLACK);    
}