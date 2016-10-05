#include <unistd.h>
#include "BlackLib/BlackGPIO/BlackGPIO.h"
#include "color_selector.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

BlackLib::BlackGPIO   led_red(BlackLib::GPIO_60, BlackLib::output, BlackLib::SecureMode);
BlackLib::BlackGPIO   led_green(BlackLib::GPIO_30, BlackLib::output, BlackLib::SecureMode);
BlackLib::BlackGPIO   button(BlackLib::GPIO_115, BlackLib::input, BlackLib::SecureMode);
BlackLib::BlackGPIO   ledR(BlackLib::GPIO_50, BlackLib::output, BlackLib::SecureMode);
BlackLib::BlackGPIO   ledG(BlackLib::GPIO_51, BlackLib::output, BlackLib::SecureMode);
BlackLib::BlackGPIO   ledB(BlackLib::GPIO_2, BlackLib::output, BlackLib::SecureMode);
ColorSelector         color_selector = ColorSelector(1);
vector<string> colors_seq;
vector<string> colors_choosen;
string status_player;

void highAll() {
  ledR.setValue(BlackLib::high);
  ledG.setValue(BlackLib::high);
  ledB.setValue(BlackLib::high);
}

void lowAll() {
  ledR.setValue(BlackLib::low);
  ledG.setValue(BlackLib::low);
  ledB.setValue(BlackLib::low);
}

void clearScreen() {
  cout << string( 100, '\n' );
}

string nextColor() {
  srand(time(NULL));
  int number = rand()%(4-1);

  if (number == 1) {
    return "red";
  }
  else if (number == 2) {
    return "green";
  }
  else {
    return "blue";
  }
}

void printSequence() {
  highAll();
  sleep(1);
  lowAll();
  sleep(1);

  for (int i = 0; i < colors_seq.size(); ++i) {
    if (colors_seq.at(i) == "red") {
      ledR.setValue(BlackLib::high);
      ledG.setValue(BlackLib::low);
      ledB.setValue(BlackLib::low);
    } else if (colors_seq.at(i) == "green") {
      ledR.setValue(BlackLib::low);
      ledG.setValue(BlackLib::high);
      ledB.setValue(BlackLib::low);
    } else if (colors_seq.at(i) == "blue") {
      ledR.setValue(BlackLib::low);
      ledG.setValue(BlackLib::low);
      ledB.setValue(BlackLib::high);
    }
    sleep(2);
    lowAll();
    sleep(1);
  }

  highAll();
  sleep(1);
  lowAll();
}

int main(int argc, char* argv[]) {
  clearScreen();

  status_player = "playing";

  while (status_player != "game_over") {
    led_green.setValue(BlackLib::low);
    led_red.setValue(BlackLib::low);
    
    colors_seq.push_back(nextColor());

    printSequence();

    highAll();
    sleep(1);
    lowAll();

    while(colors_choosen.size() != colors_seq.size()) {
      if (button.getValue() == "1") {
        if (color_selector.getAnalogValue() >= 0 && color_selector.getAnalogValue() < 1333) {
          colors_choosen.push_back("red");
          printf("Você escolheu vermelho!\n");
        } else if (color_selector.getAnalogValue() >= 1333 && color_selector.getAnalogValue() < 2666) {
          colors_choosen.push_back("green");
          printf("Você escolheu verde!\n");
        } else if (color_selector.getAnalogValue() >= 2666 && color_selector.getAnalogValue() < 4000) {
          colors_choosen.push_back("blue");
          printf("Você escolheu azul!\n");
        }
      } else {
        printf("Escolha uma cor...\n");
        if (color_selector.getAnalogValue() >= 0 && color_selector.getAnalogValue() < 1333) {
          ledR.setValue(BlackLib::high);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
        } else if (color_selector.getAnalogValue() >= 1333 && color_selector.getAnalogValue() < 2666) {
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::high);
          ledB.setValue(BlackLib::low);
        } else if (color_selector.getAnalogValue() >= 2666 && color_selector.getAnalogValue() < 4000) {
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::high);
        }
      }

      sleep(1);
    }

    for (int i = 0; i < colors_seq.size(); ++i) {
      if (colors_seq.at(i) != colors_choosen.at(i)) {
        status_player = "game_over";
      }
    }

    if (status_player != "game_over") {
      printf("Parabéns! Você acertou a sequência!! \n");
      clearScreen();
      led_green.setValue(BlackLib::high);
      highAll();
      sleep(1);
      lowAll();
      led_green.setValue(BlackLib::low);
      colors_choosen.clear();
    }
  }

  led_red.setValue(BlackLib::high);
  highAll();
  sleep(1);
  lowAll();
  led_red.setValue(BlackLib::low);
}