#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        if (r * c != mat.size() * mat[0].size())
            return mat;
        vector<vector<int>> result(r, vector<int>{});
        int i = 0;
        for (const vector<int> &line : mat)
        {
            for (const int &item : line)
            {
                if (result[i].size() > c - 1)
                    i++;
                result[i].push_back(item);
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat{{1, 2}, {3, 4}};
    for (const auto &line : s.matrixReshape(mat, 1, 4))
        for (const auto &item : line)
            std::cout << item << std::endl;
}