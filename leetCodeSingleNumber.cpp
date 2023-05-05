/* task condition
https://leetcode.com/problems/single-number/
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> nums{4,1,2,1,2};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //int iRes;
        sort(nums.begin(), nums.end());
        int iSize = nums.size();
        for(int i=0; i < iSize; i+=2)
        {
            if((i+1) >= iSize)
                return nums[i];
            if(nums[i] != nums[i+1])
                return nums[i];
        }
        return -1;
    }
};

int main()
{
    Solution sln;
    int iRes = sln.singleNumber(nums);
    cout << iRes;
    return 0;
}
