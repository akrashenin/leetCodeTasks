/* task condition
https://leetcode.com/problems/merge-intervals/
*/
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> intervals{vector<int>{1,3},vector<int>{4,6},vector<int>{8,10}, vector<int>{11,18}};

class Solution {
vector<vector<int>> vecRes;
vector<int> vecIn;
vector<int> vecNext;
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int iSize = intervals.size();
        vecIn = intervals[0];
        for(int i = 1; i < iSize; i++)
        {
            vecNext = intervals[i];
            if(vecIn[1] >= vecNext[0]){
                vecIn[1] = vecNext[1];
            }
            else
            {
                vecRes.push_back(vecIn);
                vecIn = intervals[i];
            }
        }
        vecRes.push_back(vecIn);
        return vecRes;
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> vecOut;
    vecOut = sln.merge(intervals);

    for(auto& val: vecOut)
    {
        cout << "[" << val[0] << "," << val[1] << "]" << '\t';
    }

    return 0;
}
