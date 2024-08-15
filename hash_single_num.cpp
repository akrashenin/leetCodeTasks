#include <iostream>
#include <vector>

using namespace std;

vector<int> nums{ 2,2,1 };
//vector<int> nums{ 4, 1, 2, 1, 2 };
//vector<int> nums{ 1 };

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        size_t uCount;
        size_t uSize =nums.size();

        for (size_t i = 0; i < uSize; i++)
        {
            uCount = 1;
            for (size_t j = 0; j < uSize; j++)
            {
                if (nums[i] == nums[j] && i != j)
                    uCount++;
            }
            if (uCount == 1)
                return nums[i];
        }
        return -1;
    }
};

int main()
{
    std::cout << "It's work!\n";
    Solution sln;
    int iRes = sln.singleNumber(nums);

    cout << iRes;
}

