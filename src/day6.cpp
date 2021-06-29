#include "day6.h"
#include <iostream>
#include <range/v3/all.hpp>
#include <fmt/core.h>

Group::Group() : uniq_ques{ } {};

auto Group::init(Answers &ans, std::string grp_ans) -> Answers::size_type {
  using namespace ranges;

  auto insert_into = [&ans](auto const& str_v) mutable {
    for ( char x : str_v) {
      ans.insert(x);
    }
  };

  for_each(grp_ans | views::split('\n'), insert_into);
  return ans.size();
}

std::istream& operator>> (std::istream& is, std::string& op) {
  std::string line;
  while( std::getline(is, line) && !line.empty()) {
    op.append(line);
  }
  return is;
}


int main() {
  Group test_grp = Group{};
  Answers unique{};
  auto sum = 0;

  std::string grp_ans;
  while(std::cin >> grp_ans) {
    fmt::print("dbg: parsed {}\n", grp_ans);
    sum += test_grp.init(unique, grp_ans);
    unique.clear();
    grp_ans.clear();
  }
  fmt::print("The answer is: {}\n", sum);

}
