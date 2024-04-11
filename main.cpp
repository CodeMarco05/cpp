#include <random>

PortOut leds(PortC, 0xFF);
InterruptIn taste(PC_13);

enum Zustaende { LAUFLICHT, FARBBALKEN, LICHTSPIEL };

int aktZustand;

void lauflicht() {
  if (leds == 0 || leds == 256) {
    leds = 128;
  } else {
    leds = leds >> 1;
  }

  thread_sleep_for(500);
}

void farbbalken() {
  if (leds == 255 || leds == 256) {
    leds = 128;
  } else {
    leds = leds + leds / 2;
  }

  thread_sleep_for(500);
}

int getRandomIntInRange(int min, int max) {
  std::random_device rd;  // Obtain a random number from hardware
  std::mt19937 gen(rd()); // Seed the generator
  std::uniform_int_distribution<> distr(min, max);
  return distr(gen);
}
int numbers[] = {1, 2, 4, 8, 16, 32, 64, 128};
void lichtspiel() {
  leds = 0;
  leds = numbers[getRandomIntInRange(0, 7)];
}

void isr_taste() {
  aktZustand = aktZustand + 1 % 3;
  leds = 256;
}

void init() {
  taste.mode(PullDown);
  taste.rise(&isr_taste);

  aktZustand = LAUFLICHT;
}

int main() {

  init();

  while (true) {
    switch (aktZustand) {
    case LAUFLICHT:
      lauflicht();
      break;
    case FARBBALKEN:
      farbbalken();
      break;
    case LICHTSPIEL:
      lichtspiel();
      break;
    }
  }
}
