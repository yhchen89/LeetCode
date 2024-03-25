/*------------------------------------
INPUT: Given a string amd a number of rows
OUTPUT: Return a string written in a zigzag pattern
ALGORITHM: 
演算法簡單但效率差
------------------------------------*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, const int numRows) {
        if(numRows == 1) 
            return s;
        vector<string> str(numRows, "");
        int strIndex = 0;
        bool flag = false;
        for(int sIndex = 0; sIndex < s.length(); sIndex++) {
            str[strIndex] = str[strIndex] + s[sIndex];
            if(flag) {
                strIndex--;
            }
            else {
                strIndex++;
            }
            if(strIndex == 0)
                flag = false;
            else if(strIndex == (numRows - 1) )
                flag = true;
        }

        string result;
        for(int i = 0; i < numRows; i++) {
            result = result + str[i];
        }

        return result;
    }
};

int main() {
    Solution s;
    cout<<s.convert("PAYPALISHIRING", 1)<<endl;
    cout<<s.convert("PAYPALISHIRING", 4)<<endl;
    cout<<s.convert("P", 1)<<endl;
}