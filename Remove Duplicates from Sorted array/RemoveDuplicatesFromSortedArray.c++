#include <iostream>
#include <vector>
using namespace std;
using std::vector;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < nums.size() - 1 && nums[i] == nums[i + 1])
            {
                nums.erase(i + 1);
            }
        }
    }
};

int printVector(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
}

int main()
{
    std::vector<int> vec;
    vec.push_back(3);
    std::cout << vec[0] << " ";
}