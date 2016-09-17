#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H


#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<stdlib.h>
using namespace std;

#define COLOR_SELECTOR_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"

class ColorSelector{
   private:
      int number;

   public:
      ColorSelector(int number);
      int getNumber();
      void setNumber(int number);
      int getAnalogValue();
};

#endif
