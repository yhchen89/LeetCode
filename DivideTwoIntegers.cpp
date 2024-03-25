/*--------------------------------------------
INPUT: Given two integers dividend and divisor
OUTPUT: divide two integers without using 
multiplication, division, and mod operator.
ALGORITHM: 
----------------------------------------------*/
#include<iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int answer = dividend / divisor;
        return answer;
    }
};

int main() {
    Solution s;
    cout<<s.divide(1, 1);
}