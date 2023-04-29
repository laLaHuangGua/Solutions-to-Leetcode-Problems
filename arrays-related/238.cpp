#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        size_t size = nums.size();
        vector<int> frontProduct(size + 1);
        frontProduct[0] = 1;
        vector<int> backProduct(size + 1);
        backProduct[0] = 1;
        vector<int> resultProduct(size);
        for (size_t i = 0, j = size - 1; j != 0; ++i, --j)
        {
            frontProduct[i + 1] = frontProduct[i] * nums[i];
            backProduct[i + 1] = backProduct[i] * nums[j];
        }
        for (size_t i = 0; i < size; ++i)
            resultProduct[i] = frontProduct[i] * backProduct[size - 1 - i];

        return resultProduct;
    }
};

// Better Solution: (invented by other person)
// class Solution
// {
// public:
//     vector<int> productExceptSelf(vector<int> &nums)
//     {
//         size_t size = nums.size();
//         vector<int> result(size, 1);
//         int right = 1;
//         int left = 1;
//         for (int i = 1; i < size; i++)
//         {
//             left *= nums[i - 1];
//             right *= nums[size - i];
//             result[i] *= left;
//             result[size - 1 - i] *= right;
//         }
//         return result;
//     }
// };