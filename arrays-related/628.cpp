#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution {
public:
  int maximumProduct(vector<int> &nums) {
    if (nums.size() == 3)
      return nums.at(0) * nums.at(1) * nums.at(2);
    else {
      sort(nums.begin(), nums.end());
      int three_positive =
          *(nums.rbegin()) * *(nums.rbegin() + 1) * *(nums.rbegin() + 2);
      int one_positive =
          *(nums.begin()) * *(nums.begin() + 1) * *(nums.rbegin());
      if (three_positive > one_positive)
        return three_positive;
      else
        return one_positive;
    }
  }
};