#include <chrono>
#include <iostream>
#include <thread>
#include "Miner.hpp"

int main() {
  using namespace std::chrono_literals;
  DigGold startState;
  Miner bob(1, startState);

  for (int i = 0; i < 10; i++) {
    bob.update();

    std::this_thread::sleep_for(2s);
  }

  while (getchar() != '\n')
    ;

  return 0;
}