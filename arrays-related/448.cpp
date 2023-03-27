#include <algorithm>
#include <numeric>

using std::iota;
using std::vector;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<int> init(nums.size());
    vector<int> result{};
    iota(init.begin(), init.end(), 1);
    for (int i = 0; i < nums.size(); i++)
      init.at(nums.at(i) - 1) = 0;
    for (int j = 0; j < init.size(); j++) {
      if (!(init.at(j) == 0))
        result.push_back(init.at(j));
    }
    return result;
  }
};