#include <iostream>
#include <vector>
using namespace std;

int maxProductDifference(vector<int> &nums)
{

    int max = 0, sMax = 0, min = 10001, sMin = 10001;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > max)
        {
            sMax = max;
            max = nums[i];
        }
        else if (nums[i] > sMax)
        {
            sMax = nums[i];
        }

        if (nums[i] < min)
        {
            sMin = min;
            min = nums[i];
        }
        else if (nums[i] < sMin)
        {
            sMin = nums[i];
        }
    }
    cout << max << " " << sMax << endl;
    cout << min << " " << sMin << endl;

    return (max * sMax) - (min * sMin);
}

int main()
{
    vector<int> nums = {5, 9, 4, 6};
    cout << maxProductDifference(nums);
    return 0;
}