#include <fmt/core.h>
#include <iostream>
#include <map>
#include <range/v3/action/insert.hpp>
#include <range/v3/algorithm/count.hpp>
#include <range/v3/algorithm/count_if.hpp>
#include <range/v3/view/enumerate.hpp>
#include <range/v3/view/join.hpp>
#include <range/v3/view/map.hpp>
#include <range/v3/view/split.hpp>
#include <set>
#include <string>
#include <string_view>

// This is useful when just trying things out
// #include <range/v3/all.hpp>

typedef std::set<char> Answers;
typedef std::map<char, int> AnsMap;

auto
unique_answers(Answers& ans, const std::string_view grp_ans)
  -> Answers::size_type
{
  using namespace ranges;

  actions::insert(ans, grp_ans | views::split('\n') | views::join);
  return ans.size();
}

auto
common_answers(AnsMap& ans, const std::string_view grp_ans) -> AnsMap::size_type
{
  using namespace ranges;

  auto freq = count_if(grp_ans, [member_count, &grp_ans](char x) {
    return count(grp_ans, x) == member_count;
  });
  // Remove duplicates and don't count newlines
  return (freq / member_count);
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
    std::string_view group_answers_view{ grp_ans };
    uniques += unique_answers(unique, group_answers_view);
    commons += common_answers(common, group_answers_view);

    unique.clear();
    common.clear();
    grp_ans.clear();
  }
  fmt::print("#Unique Answers = {}\n", uniques);
  fmt::print("#Common Answers = {}\n", commons);
}
