#include "color_selector.h"

ColorSelector::ColorSelector(int number) {
  this->number = number;
}

int ColorSelector::getNumber() {
  return this->number;
}

void ColorSelector::setNumber(int number) {
  this->number = number;
}

int ColorSelector::getAnalogValue() {
  int analog_value;
  stringstream ss;

  ss << COLOR_SELECTOR_PATH << this->number << "_raw";
  fstream fs;
  fs.open(ss.str().c_str(), fstream::in);
  fs >> analog_value;
  fs.close();

  return analog_value;
}