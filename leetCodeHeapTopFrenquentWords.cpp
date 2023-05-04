/* task conditional
https://leetcode.com/problems/top-k-frequent-words/
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> words{"the","day","is","sunny","the","the","the","sunny","is","is"};
int k = 4;
//vector<string> words{"i","love","leetcode","i","love","coding"};
//int k = 2;

using VecStr = vector<string>;
using UMapStrInt = unordered_map<string, int>;

class Solution {
unordered_map<string, int> mapStr;
unordered_map<string, int>::iterator iter;
vector<string> vecOut;
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        sort(words.begin(), words.end());

        for(auto& val: words)
        {
            iter = mapStr.find(val);
            if( iter == mapStr.end())   // not found
                mapStr.insert(pair<string, int>(val, 1));
            else
                iter->second++;
        }
        for(int l=0; l < k; l++)
        {
            string str("");
            int iFrenc = 0;
            for(iter = mapStr.begin(); iter != mapStr.end(); iter++)
            {
                if(iter->second > iFrenc)
                {
                    str = iter->first;
                    iFrenc = iter->second;
                }
                if(iter->second == iFrenc)
                {
                    if(str.compare(iter->first) > 0)
                    {
                        str = iter->first;
                        iFrenc = iter->second;
                    }

                }
            }
            vecOut.push_back(str);
            mapStr.erase(str);
        }

        return vecOut;
    }
};

int main(int argc, char* argv[])
{
    Solution sln;
    VecStr vec;
    vec = sln.topKFrequent(words, k);

    for(auto& val: vec)
    {
        cout << val << '\t';
    }

    return 0;
}
