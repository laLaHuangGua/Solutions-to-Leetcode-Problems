#include <stddef.h>

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int p = 1;
        int q = 1;
        int result = 2;
        for (size_t i = 0; i < n - 2; i++) {
            p = q;
            q = result;
            result = q + p;
        }
        return result;
    }
};