#pragma once
#include <cstdio>
#include <string>

static inline void RaiseInterpreterError(std::string &&errorMsg) {
  fprintf(stderr, "[CRIT] %s\n", errorMsg.c_str());
  exit(1);
}
