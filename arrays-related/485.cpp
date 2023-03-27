#include <vector>

using std::vector;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int result = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums.at(i)) {
        count++;
        if (i + 1 == nums.size()) {
          if (count > result)
            result = count;
          break;
        }
      } else {
        if (count > result)
          result = count;
        count = 0;
      }
    }
    return result;
  }
};