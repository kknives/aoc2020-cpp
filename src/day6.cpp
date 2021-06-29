#include "day6.h"
#include <iostream>
#include <range/v3/all.hpp>
#include <fmt/core.h>

auto unique_answers(Answers &ans, std::string grp_ans) -> Answers::size_type {
  using namespace ranges;

  for (auto&& [i, str_v] : grp_ans | views::split('\n') | views::enumerate) {
    fmt::print("Line {}\n", i);
    for ( char x : str_v) {
      ans.insert(x);
    }
  };
  return ans.size();
}

std::istream& operator>> (std::istream& is, std::string& op) {
  std::string line;
  while( std::getline(is, line) && !line.empty()) {
    op.append(line+'\n');
  }
  return is;
}


int main() {
  Answers unique{};
  auto sum = 0;

  std::string grp_ans;
  while(std::cin >> grp_ans) {
    // fmt::print("dbg: parsed {}\n", grp_ans);
    sum += unique_answers(unique, grp_ans);
    unique.clear();
    grp_ans.clear();
  }
  fmt::print("The answer is: {}\n", sum);

}
