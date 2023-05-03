/* task condition
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> vec{7,1,5,3,6,4};

class Solution {
    int iProfit = 0;
public:
    int maxProfit(vector<int>& prices) {
        int iCount = prices.size();
        for(int i=0; i < (iCount-1); i++)
        {
            if(prices[i] < prices[i+1] )
                iProfit += prices[i+1] - prices[i];
        }
        return iProfit;
    }
};



int main()
{
    Solution sln;

    for(auto& val: vec)
    {
        cout << val << '\t';
    }
    cout << endl;

    cout << sln.maxProfit(vec);

    return 0;
}
