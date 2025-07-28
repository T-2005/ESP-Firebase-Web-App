#ifndef light_H
#define light_H 

#include<Arduino.h>

extern int check;
extern int value_of_sensor;
class light {
  public:
  static void read_light_sensor(); // đọc giá trị cảm biến ánh sáng
  static void check_and_clear_oled(const int& value_of_sensor,  int& check); // kiểm tra xem led đang ở trạng thái bật hay tắt và thực hiện xóa kí tự trên màn oled
  static void led_sensor(); // điều khiển led bằng cảm biến ánh sáng và hiển thị lên màn hình oled
  static void on_off_led(const int& value_of_sesor); // bật tắt led
};

#endif