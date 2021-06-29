#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <set>

typedef std::set<char> Answers;

class Group {
  std::vector<char> uniq_ques;
  public:
  Group();
  auto init(Answers &ans, std::string) -> Answers::size_type;
};
