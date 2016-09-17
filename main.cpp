#include <unistd.h>
#include "BlackLib/BlackGPIO/BlackGPIO.h"
#include<iostream>

using namespace std;

int main(int argc, char* argv[]) {
  BlackLib::BlackGPIO led_vermelho(BlackLib::GPIO_50,BlackLib::output, BlackLib::SecureMode);

  if (led_verde.getDirection() == 2) {
    cout << "O led verde está OUT" << endl;
  } else {
    cout << "Tem alguma coisa errada :(" << endl;
  }

  sleep(5);

  cout << "Ligando LED..." << endl;

  led_verde.setValue(BlackLib::high);

  if (led_verde.isHigh()) {
    cout << "LED está ligado" << endl;
  } else {
    cout << "Tem alguma coisa errada :(" << endl;
  }

  sleep(5);

  cout << "Desligando LED..." << endl;

  led_verde.setValue(BlackLib::low);

  if (led_verde.getValue() == "0") {
    cout << "LED está desligado" << endl;
  } else {
    cout << "Tem alguma coisa errada :(" << endl;
  }
}