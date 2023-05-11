#include <stack>
#include <unordered_map>
#include <vector>

using std::stack;
using std::unordered_map;
using std::vector;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> s{};
        unordered_map<int, int> map{};
        for (int i : nums2)
        {
            while (!s.empty() && i > s.top())
            {
                map.emplace(s.top(), i);
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty())
        {
            map.emplace(s.top(), -1);
            s.pop();
        }
        vector<int> result{};
        for (int i : nums1)
            result.push_back(map[i]);
        return result;
    }
};