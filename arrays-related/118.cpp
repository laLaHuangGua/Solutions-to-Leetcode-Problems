#include <vector>

using std::vector;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> nums{};
    nums.push_back(vector<int>{1});
    if (numRows == 1)
      return nums;
    nums.push_back(vector<int>{1, 1});
    if (numRows == 2)
      return nums;

    for (int i = 2; i < numRows; i++) {
      nums.push_back(vector<int>{1});
      for (int j = 0; j <= nums.at(i - 1).size(); j++) {
        if (j + 1 == nums.at(i - 1).size()) {
          nums.at(i).push_back(1);
          break;
        }
        nums.at(i).push_back(nums.at(i - 1).at(j) + nums.at(i - 1).at(j + 1));
      }
    }
    return nums;
  }
};