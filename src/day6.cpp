#include "day6.h"
#include <cstdio>
#include <range/v3/all.hpp>

Group::Group() : uniq_ques{ } {};

auto Group::init(std::string grp_ans) -> size_t {
  using namespace ranges;

  auto are = [](char look_for) {
    return [look_for](char candidate) { return candidate == look_for; };
  };
  auto insert_if = [this, are](char x) {
    if (none_of(uniq_ques, are(x))) {
      uniq_ques.push_back(x);
      printf("dbg: %d\n", x);
    }
  };

  grp_ans.erase(ranges::remove(grp_ans, '\n'));
  for_each(grp_ans, insert_if);

  return uniq_ques.size();
}

int main() {
  Group test_grp = Group{};
  auto q = test_grp.init("a\nb\nc\n");
  printf("result : %ld\n", q);
}
