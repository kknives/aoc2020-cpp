#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <set>
#include <map>

typedef std::set<char> Answers;
typedef std::map<char, int> AnsMap;

auto unique_answers(Answers &ans, std::string grp_ans) -> Answers::size_type;
auto common_answers(AnsMap &ans, std::string grp_ans) -> AnsMap::size_type;
