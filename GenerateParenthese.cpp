/*------------------------------
INPUT: Given n pairs of parentheses
OUTPUT: generate all combinations of well-formed parentheses
ALGORITHM: 
-------------------------------*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> ret;
    void generate(int n, string parentheses, int left, int right) {
        if(right == n){
            ret.push_back(parentheses);
        }
            
        else if(right == left) {
            generate(n, parentheses + "(", left + 1, right);
        }
        else if(right < left) {
            generate(n, parentheses + ")", left, right + 1);
            if(left != n)
                generate(n, parentheses + "(", left + 1, right);
        }
    }
    vector<string> generateParenthesis(int n) {
        string parentheses = "(";
        int left = 1, right = 0;
        
        generate(n, parentheses, left, right);
        cout<<ret.size();
        return ret;
    }
};

int main() {
    Solution s;
    cout<<s.generateParenthesis(3).size();
}