#pragma once

#include <string>
#include <vector>

class LexicalAnalyser {
public:
  LexicalAnalyser(std::string line);

  std::vector<std::string> splitLineForTokenizer(std::string &&line);

private:
  std::string p_line;
};
