/* task condition
https://leetcode.com/problems/sliding-window-median/
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//vector<int> nums{1,3,-1,-3,5,3,6,7};
vector<int> nums{1,2,3,4,2,3,1,4,2};
int k = 3;

class Solution {
vector<double> dblVec;
vector<int>::iterator iter;
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<int> vecAux(k);
        double dblVal;
        int iValTmp = k % 2;
        double dblInd = floor(k/2);
        if(iValTmp == 0)
            dblInd--;

        dblVec.clear();
        int iSize = nums.size();
        if(iSize < k)
            return dblVec;

        iter = nums.begin();
        for(int i=0; i<=(iSize-k); i++, iter++)
        {
            vecAux.clear();
            copy_n(iter, k, vecAux.begin());
            sort(vecAux.begin(), vecAux.begin()+k);
            if(iValTmp == 0)
            {
                dblVal = (double)(vecAux[dblInd] + vecAux[dblInd+1])/2;
                dblVec.push_back(dblVal);
            }
            else
                dblVec.push_back(vecAux[dblInd]);
        }
        return dblVec;
    }
};

int main()
{
    Solution sln;
    vector<double> dblVecOut;
    dblVecOut = sln.medianSlidingWindow(nums,k);

    for(auto& val: dblVecOut)
        cout << val << '\t';

    return 0;
}
