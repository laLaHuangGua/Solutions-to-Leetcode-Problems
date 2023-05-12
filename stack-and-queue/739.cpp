#include <stack>
#include <vector>

using std::stack;
using std::vector;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> s{};
        vector<int> result(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                result[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty())
        {
            result[s.top()] = 0;
            s.pop();
        }
        return result;
    }
};