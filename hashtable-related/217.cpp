#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s{};
        for (int num : nums)
        {
            if (s.find(num) != s.end())
                return true;
            s.insert(num);
        }
        return false;
    }
};