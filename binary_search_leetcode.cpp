// https://leetcode.com/problems/binary-search/description/
#include <iostream>
#include <vector>
#include <algorithm>

#define TARGET  2
using namespace std;
vector<int> vec{ -1,0,3,5,9 };

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int iLeft = 0;
        int iRight = nums.size() - 1;

        sortArr(nums);

        for (int i = 0; i < nums.size(); i++)
        {
            int iTagCalc = (iLeft + iRight) / 2;
            if (target == nums[iTagCalc])
                return iTagCalc;    // If target exists, then return its index. Otherwise, return -1. 
            if (target > nums[iTagCalc])
                iLeft = iTagCalc + 1;
            if(target < nums[iTagCalc])
                iRight = iTagCalc - 1;
            if (iLeft > iRight)
                break;
        }
        return -1;
    }
private:
    void sortArr(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
    }
};

int main(int argc, char *argv[])
{
    cout << "It's work!!!\n";
    Solution sln;
    int iRes = sln.search(vec, TARGET);
    cout << "Result of seach: " << iRes << endl;
    return 0;
}

