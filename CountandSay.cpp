/*-------------------------------------------------------
INPUT: Given a positive integer n
OUTPUT: Return the nth term of the count-and-say sequence
ALGORITHM: recursive
--------------------------------------------------------*/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        else {
            string s = countAndSay(n - 1);
            string ret;
            char c[1] = "";
            int count = 0;
            
            for(int i = 0; i < s.length(); i++) {
                if(s[i] != c[0]) {
                    if(i != 0)
                        ret = ret + to_string(count) + c[0];
                    c[0] = s[i];
                    count = 1;
                }
                else 
                    count++;
            }
            ret = ret + to_string(count) + c[0];
            return ret;
        }
    }
};

int main() {
    Solution s;
    cout<<s.countAndSay(10)<<endl;
}
