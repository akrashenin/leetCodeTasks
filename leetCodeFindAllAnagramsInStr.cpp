/* task condition
https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//string s = "cbaebabacd";
//string p = "abc";

string s = "abab";
string p = "ab";

class mySort{
public:
    bool operator () (char f, char s){ return (f<s);}
} mysort;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vecOut{};
        string subStr;
        int iSizeS = s.size();
        int iSizeP = p.size();
        if(iSizeS < iSizeP)
            return vecOut;
        sort(p.begin(), p.end());
        for(int i = 0; i < (iSizeS-iSizeP+1); i++)
        {
            subStr = s.substr(i, iSizeP);
            sort(subStr.begin(), subStr.end());
            if(!p.compare(subStr))
                vecOut.push_back(i);
        }
        return vecOut;
    }
};

int main(int argc, char *argv[])
{
    //sort(s.begin(),s.begin() + s.size(), mysort);
    vector<int> vecOut;
    Solution sln;
    vecOut = sln.findAnagrams(s,p);
    for(auto& val: vecOut)
        cout << val << '\t';

    return 0;
}
