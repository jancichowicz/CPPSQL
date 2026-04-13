#pragma once 

#include <array>
#include <string_view>

enum class GeneralTokens {
  ACTION,
  RVAL,
  LVAL,
  CONIUNCTIVE,
  OBJECTS
};

enum class ActionTokens {
  SELECT,
  INSERT,
  DROP,
  USE
};

enum class ConiunctiveTokens {
  FROM,
  INTO,
  VALUES
};

enum class ObjectTokens {
  DATABASE,
  TABLE 
};

constexpr std::array<std::string_view, 4> ActionKeywords{{
  "SELECT",
  "INSERT",
  "DROP",
  "USE"
}};

constexpr std::array<std::string_view, 3> ConiunctiveKeywords{{
  "FROM",
  "INTO",
  "VALUES"
}};

constexpr std::array<std::string_view, 2> ObjectKeywords{{
  "DATABASE",
  "TABLE"
}};
