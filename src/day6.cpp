#include <fmt/core.h>
#include <iostream>
#include <range/v3/action/insert.hpp>
#include <range/v3/algorithm/count.hpp>
#include <range/v3/algorithm/count_if.hpp>
#include <set>
#include <string>
#include <string_view>

// This is useful when just trying things out
// #include <range/v3/all.hpp>

typedef std::set<char> Answers;

auto
unique_answers(Answers& ans, const std::string_view grp_ans)
  -> Answers::size_type
{
  ranges::actions::insert(ans, grp_ans);
  return ans.size();
}

auto
common_answers(const int member_count, const std::string_view grp_ans) -> int
{
  using namespace ranges;

  auto freq = count_if(grp_ans, [member_count, &grp_ans](char x) {
    return count(grp_ans, x) == member_count;
  });
  // Remove duplicates
  return (freq / member_count);
}

struct Input
{
  int line_count;
  std::string lines;
};

std::istream&
operator>>(std::istream& is, Input& res)
{
  std::string line;
  for (res.line_count = 0; std::getline(is, line) && !line.empty();
       res.line_count++) {
    res.lines.append(line);
  }
  return is;
}

int
main()
{
  Answers unique{};
  auto uniques = 0;
  auto commons = 0;

  Input input{};

  while (std::cin >> input) {
    std::string_view group_answers_view{ input.lines };
    uniques += unique_answers(unique, group_answers_view);
    commons += common_answers(input.line_count, group_answers_view);

    unique.clear();
    input.lines.clear();
  }
  fmt::print("#Unique Answers = {}\n", uniques);
  fmt::print("#Common Answers = {}\n", commons);
}
