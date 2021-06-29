#include "day6.h"
#include <cstdio>
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

int main() {
  Group test_grp = Group{};
  auto q = test_grp.init("a\nb\nc\n");
  printf("result : %ld\n", q);
}
