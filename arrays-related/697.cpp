#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
public:
  int findShortestSubArray(vector<int> &nums) {
    unordered_map<int, vector<int>> map;

    for (int i = 0; i < nums.size(); i++) {
      if (empty(map))
        map.emplace(nums.at(i), vector<int>{i, i, 1});
      else {
        if (auto search = map.find(nums.at(i)); search != map.end()) {
          search->second.at(1) = i;
          search->second.at(2) += 1;
        } else
          map.emplace(nums.at(i), vector<int>{i, i, 1});
      }
    }

    auto target = map.begin();
    for (auto iter = ++map.begin(); iter != map.end(); iter++) {
      if (iter->second.at(2) > target->second.at(2))
        target = iter;
      else if (iter->second.at(2) < target->second.at(2))
        continue;
      else if (iter->second.at(1) - iter->second.at(0) <
               target->second.at(1) - target->second.at(0))
        target = iter;
    }

    return target->second.at(1) - target->second.at(0) + 1;
  }
};