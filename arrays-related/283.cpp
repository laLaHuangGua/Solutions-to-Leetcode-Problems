#include <vector>

using std::vector;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int min_valid_position = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums.at(i) != 0) {
        while (min_valid_position < nums.size() &&
               nums.at(min_valid_position) != 0)
          min_valid_position++;
        if (min_valid_position >= nums.size())
          return;

        if (min_valid_position < i) {
          nums.at(min_valid_position) = nums.at(i);
          nums.at(i) = 0;
          min_valid_position++;
        }
      }
    }
  }
};