#ifndef pin_H
#define pin_H

#include<Arduino.h>

extern int D0;
extern int Led;

class pin {
  public:
  static void init();
};

#endif