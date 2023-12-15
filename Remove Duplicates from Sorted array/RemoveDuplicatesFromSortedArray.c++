#include <iostream>
#include <vector>
using namespace std;

// erase solution
// int removeDuplicates(vector<int> &nums)
// {
//     for (int i = 0; i + 1 < nums.size(); ++i)
//     {
//         if (nums[i] == nums[i + 1])
//         {
//             nums.erase(nums.begin() + i);
//             i--;
//         }
//     }

//     return nums.size();
// }

int removeDuplicates(vector<int> &nums)
{
    int iterator = 0;
    for (int i = 0; i + 1 < nums.size(); ++i)
    {
        if (nums[i] != nums[i + 1])
        {
            nums[iterator + 1] = nums[i + 1];
            iterator++;
        }
    }
    return iterator + 1;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4};
    cout << removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }

    return 0;
}