#pragma once

#include <vector>
#include <string>
#include <string_view>

class Group {
  std::vector<char> uniq_ques;
  public:
  Group();
  auto init(std::string) -> size_t;
};
