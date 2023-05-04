/* task conditional
https://leetcode.com/problems/container-with-most-water/
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> height{1,8,6,2,5,4,8,3,7};

class Solution {
int m_SquareMax = 0;
public:
    int maxArea(vector<int>& height) {
        int iWidth = 0;
        int iHeight = 0;
        int iSquare = 0;
        int iSize = height.size();
        for(int i=0; i < iSize; i++)
        {
            if(i == 8)
                ;
            for(int j=0; j < iSize; j++)
            {
                if(i == j)
                    break;

                iWidth = abs(i - j);
                if(height[i] > height[j])
                    iHeight = height[j];
                else
                    iHeight = height[i];
                iSquare = iWidth * iHeight;
                if(iSquare > m_SquareMax)
                    m_SquareMax = iSquare;
            }
        }
        return m_SquareMax;
    }
};

int main(int argc, char *argv[])
{
    Solution sln;
    int iRes = sln.maxArea(height);
    cout << iRes;

    return 0;
}
