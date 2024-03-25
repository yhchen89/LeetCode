/*---------------------------------------------------------------------
INPUT: an array of strings
OUTPUT: the longest common prefix string
NOTICE: If there is no common prefix, return an empty string ""
ALGORUTHM: start from index=0, check each element whether the character
 is the same ,if the same push the character to the answer ,if not or
  to the end('\0'), stop checking and return.
----------------------------------------------------------------------*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        string prefix;
        string commonPrefix = "";

        if(strs.empty())
            return "";
             
        for(int i = 0;; i++){
            prefix.clear();
            for(index = 0; index < strs.size(); index++){
                if(strs.at(index)[i] == '\0')              //key
                    return commonPrefix;
                if(index == 0)
                    prefix = prefix + strs.at(index)[i];
                else {
                    if(prefix.at(0) != strs.at(index)[i]) 
                        return commonPrefix;
                }
            }
            commonPrefix = commonPrefix + prefix;
        }

        return commonPrefix;
    }
};

int main(){
    Solution s;
    vector<string> strs = {""};
    cout<<s.longestCommonPrefix(strs)<<endl;
}