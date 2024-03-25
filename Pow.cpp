/*
INPUT: Given a x and n
OUTPUT: Return x raised to the power n
ALGORITHM: 
Constraints:
-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104
*/
#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0;
        if (n == 0)
            return 1;
        if (x == 1 || n == 1)
            return x;
        if (n % 2 == 0)
            return myPow(x * x, n/2);
        if(n > 0)
            return x * myPow(x, n-1);
        else
            return 1 / (x * myPow(x, n * (-1) - 1));
    }
};

int main() {
    Solution s;
    double x = 0.1;
    cout<<s.myPow(x, INT_MAX)<<endl;
}