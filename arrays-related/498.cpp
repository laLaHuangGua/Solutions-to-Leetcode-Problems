#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        size_t m = mat.size();
        size_t n = mat[0].size();

        vector<int> result;
        result.reserve(m * n);

        int sum = 0;

        while (sum < m + n - 1)
        {
            if (sum % 2 != 0)
            {
                int m_index = 0;
                int n_index = sum;

                while (n_index > n - 1)
                {
                    m_index++;
                    n_index--;
                }
                while (m_index < m && n_index > -1)
                    result.emplace_back(mat[m_index++][n_index--]);
                sum++;
            }
            else
            {
                int m_index = sum;
                int n_index = 0;

                while (m_index > m - 1)
                {
                    m_index--;
                    n_index++;
                }
                while (m_index > -1 && n_index < n)
                    result.emplace_back(mat[m_index--][n_index++]);
                sum++;
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> nums{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    for (const auto &each : s.findDiagonalOrder(nums))
        cout << each << endl;
}