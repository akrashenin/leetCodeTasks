/* Task condition
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> vec{7,1,5,3,6,4};
vector<int>::iterator iter;

class Solution {
    int iMaxVal = 0;
    vector<int>::iterator iterS, iterTmp;
public:
    int maxProfit(vector<int>& prices)
    {
        int iVal = 0;
        for(iter = prices.begin(); iter != prices.end(); iter++)
        {
            for(iterS = iter; iterS != prices.end(); iterS++)
            {
                iterTmp = iterS+1;
                if(iterTmp == prices.end())
                    break;
                iVal = *iterTmp - *iter;
                if (iVal > iMaxVal)
                    iMaxVal = iVal;
            }
        }
        return iMaxVal;
    }
};

int main()
{
    Solution sln;

    for(auto& val: vec)
        cout << val << '\t';
    cout << endl;

    cout << sln.maxProfit(vec);

}
