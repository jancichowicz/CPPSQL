#include "LexicalAnalyser.h"
#include <iostream>

void LexicalAnalyserTest(void) {
  while (1) {
    std::string temp{};
    std::cout << ">";
    std::getline(std::cin, temp);
    LexicalAnalyser la{temp};
  }
}

int main(int argc, char **argv) {
  LexicalAnalyserTest();

  return 0;
}
