#include "color_selector.h"

int main(int argc, char* argv[]) {
  ColorSelector color_selector = ColorSelector(1);

  int analog_value = color_selector.getAnalogValue();

  cout << "Valor: " << analog_value << endl;
}