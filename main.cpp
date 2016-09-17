#include "led.h"

int main(int argc, char* argv[]) {
  LED led_verde = LED(50);

  string direction = led_verde.getDirection();
  string value = led_verde.getValue();

  cout << "Direção: " << direction << endl;
  cout << "Valor: " << value << endl;
}