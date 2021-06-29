#include "day6.h"
#include <fmt/core.h>
#include <iostream>
#include <range/v3/all.hpp>

auto
unique_answers(Answers& ans, const std::string_view grp_ans) -> Answers::size_type
{
  using namespace ranges;

  for (auto&& [i, str_v] : grp_ans | views::split('\n') | views::enumerate) {
    for ( char x : str_v) {
      ans.insert(x);
    }
  };
  return ans.size();
}

auto
common_answers(AnsMap& ans, const std::string_view grp_ans) -> AnsMap::size_type
{
  using namespace ranges;

  int member_count;
  for (auto&& [i, str_v] : grp_ans | views::split('\n') | views::enumerate) {
    for (char x : str_v) {
      ans[x]++;
    }
    member_count = i + 1; // Number not index
  };
  return count_if(ans, [member_count](auto const& pair) {
    const auto& [key, count] = pair;
    return count == member_count;
  });
}

std::istream&
operator>>(std::istream& is, std::string& op)
{
  std::string line;
  while (std::getline(is, line) && !line.empty()) {
    // Preserve newlines for separating groups into members
    op.append(line + '\n');
  }
  return is;
}

int
main()
{
  Answers unique{};
  AnsMap common{};
  auto uniques = 0;
  auto commons = 0;

  std::string grp_ans;
  while (std::cin >> grp_ans) {
    // fmt::print("dbg: parsed {}\n", grp_ans);
    uniques += unique_answers(unique, grp_ans);
    commons += common_answers(common, grp_ans);
    unique.clear();
    common.clear();
    grp_ans.clear();
  }
  fmt::print("#Unique Answers = {}\n", uniques);
  fmt::print("#Common Answers = {}\n", commons);
}
