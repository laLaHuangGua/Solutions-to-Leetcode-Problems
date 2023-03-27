#include <set>
#include <vector>

using std::set;
using std::vector;

class Solution {
public:
  int thirdMax(vector<int> &nums) {
    set<int> top_three_set;
    for (int i = 0; i < nums.size(); i++) {
      top_three_set.insert(nums.at(i));
      if (top_three_set.size() > 3)
        top_three_set.erase(top_three_set.begin());
    }
    if (top_three_set.size() < 3)
      return *(top_three_set.rbegin());
    return *(top_three_set.begin());
  }
};