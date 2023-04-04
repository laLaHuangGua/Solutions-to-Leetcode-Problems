#include <algorithm>
#include <iostream>
#include <vector>

using std::swap;
using std::vector;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        size_t n = matrix.size();
        for (int i = 0; i < n / 2; i++)
            swap(matrix[i], matrix[n - i - 1]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.rotate(matrix);
    for (const auto &line : matrix)
    {
        for (const auto &item : line)
            std::cout << item << " ";
        std::cout << std::endl;
    }
}