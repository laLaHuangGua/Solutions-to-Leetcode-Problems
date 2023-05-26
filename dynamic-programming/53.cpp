#include <climits>
#include <vector>

using std::max;
using std::vector;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int prev = 0;
        int maxSubArraySum = INT_MIN;
        for (const auto &n : nums) {
            prev = max(prev + n, n);
            maxSubArraySum = max(maxSubArraySum, prev);
        }
        return maxSubArraySum;
    }
};