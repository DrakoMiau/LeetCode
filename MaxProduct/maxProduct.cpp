#include <stdio.h>
#include <vector>
using namespace std;

int maxProduct(vector<int> &nums)
{

    int v1 = 0;
    int v2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (v1 < nums[i])
        {
            v2 = v1;
            v1 = nums[i];
        }
        else if (v2 < nums[i])
        {
            v2 = nums[i];
        }
    }
}

int main()
{

    return 0;
}