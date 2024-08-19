// https://leetcode.com/problems/sliding-window-median/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
#define SIZE_WIN 3

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> vecAdv;
        vector<double> vecDbl;
        size_t uSize = nums.size();
        vector<int>::iterator iter;
        int iMid;

        for (int i = 0; i <= uSize - k; i++)
        {
            vecAdv.clear();
            for (int j = 0; j < k; j++)
            {
                int iVal = nums[i + j];
                vecAdv.push_back(iVal);
            }
            sort(vecAdv.begin(), vecAdv.end());
            iMid = floor(vecAdv.size() / 2);
            float flVal = vecAdv[iMid];
            vecDbl.push_back(flVal);
        }
        return vecDbl;
    }
};

void sortInWin(vector<int>& vec, int iPos)
{
    vector<int> vecAdv;
    size_t uSize = vec.size();
    vector<int>::iterator iter;
    int iMid;
    bool flag = false;

    printf("%s", "[");
    for (int i = 0; i <= uSize - iPos; i++)
    {
        if (flag)
        {
            printf("%s", ",");           
        }
        vecAdv.clear();        
        for (int j = 0; j < iPos; j++)
        {
            int iVal = vec[i + j];
            vecAdv.push_back(iVal);
        }
        sort(vecAdv.begin(), vecAdv.end());
        iMid = floor(vecAdv.size()/2);
        //cout << vecAdv[iMid] << " ";
        float flVal = vecAdv[iMid];
        printf("%f", flVal);
        flag = true;
    }
    printf("%s", "]");    
}

int main()
{
    std::cout << "It's work!\n";
    //sortInWin(nums, SIZE_WIN);

    Solution sln;
    vector<double> vecDbl = sln.medianSlidingWindow(nums, SIZE_WIN);
    for (auto& val : vecDbl)
    {
        cout << val << " ";
    }

}

