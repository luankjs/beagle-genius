#ifndef LED_H
#define LED_H


#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<stdlib.h>
using namespace std;

#define GPIO_PATH "/sys/class/gpio/gpio"

class LED {
   private:
      int number;
      std::string get(char type[]);

   public:
      LED(int number);
      int getNumber();
      void setNumber(int number);
      std::string getDirection();
      std::string getValue();
};

#endif
