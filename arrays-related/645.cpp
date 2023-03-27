#include <vector>

using std::vector;

class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    vector<int> result{0, 0};
    bool flag = false;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (nums.at(i) != i + 1) {
        if (nums.at(i) == i && i + 1 < nums.size() && nums.at(i + 1) == i + 1) {
          if (!flag)
            result.at(0) = nums.at(i);
          flag = true;
        } else {
          if (!flag)
            result.at(0) = nums.at(i);
          if (result.at(1) == 0)
            result.at(1) = i + 1;
        }
      } else if (flag) {
        result.at(1) = i;
        break;
      }
    }
    return result;
  }
};