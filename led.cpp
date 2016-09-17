#include "led.h"

LED::LED(int number) {
  this->number = number;
}

int LED::getNumber() {
  return this->number;
}

void LED::setNumber(int number) {
  this->number = number;
}

std::string LED::get(char type[]) {
  string value;
  stringstream ss;

  ss << GPIO_PATH << this->number << "/" << type;
  fstream fs;
  fs.open(ss.str().c_str(), fstream::in);
  fs >> value;
  fs.close();

  return value;
}

std::string LED::getDirection() {
  char type[] = "direction";
  string direction = this->get(type);

  return direction;
}

std::string LED::getValue() {
  char type[] = "value";
  string value = this->get(type);

  return value;
}