#include "LexicalAnalyser.h"

#include "logging.h"

#include <iostream>
#include <stack>

LexicalAnalyser::LexicalAnalyser(std::string line) : p_line(line) {
  std::cout << "Statring lexical analysis on instruction: " << line
            << std::endl;
  for (const auto &i : splitLineForTokenizer(std::move(p_line))) {
    std::cout << i << "|\n";
  }
}

std::vector<std::string>
LexicalAnalyser::splitLineForTokenizer(std::string &&line) {
  std::vector<std::string> ret{};

  auto firstPointer = line.begin();
  auto secondPointer = firstPointer;
  std::stack<char> parenthesisStack{};

  while (secondPointer != line.end()) {
    switch (*secondPointer) {
    case '<':
      parenthesisStack.push('<');
      break;
    case '>':
      if (parenthesisStack.top() == '<')
        parenthesisStack.pop();
      else
        RaiseInterpreterError("\'<\' expected");
      break;
    case '(':
      parenthesisStack.push('(');
      break;
    case ')':
      if (parenthesisStack.top() == '(')
        parenthesisStack.pop();
      else
        RaiseInterpreterError("\'(\' expected");
      break;
    case ' ':
      if (parenthesisStack.empty()) {
        ret.emplace_back(
            std::string(*firstPointer == ' ' ? firstPointer + 1 : firstPointer,
                        secondPointer));
        firstPointer = secondPointer;
      }
      break;
    }

    secondPointer++;
  }

  ret.emplace_back(std::string(
      *firstPointer == ' ' ? firstPointer + 1 : firstPointer, secondPointer));

  return ret;
}
