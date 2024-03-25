#include<iostream>
using namespace std;

/*
INPUT: a integer x
OUTPUT: true if x is palindrome integer
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int palindrome = 0;
        int temp=x;
        long long int digit=1;
        while(temp!=0){
            temp=temp/10;
            digit=digit*10;
        }
        temp=x;
        digit=digit/10;
        while(temp!=0){
            palindrome=palindrome+temp%10*digit;
            temp=temp/10;
            digit=digit/10;
        }
        cout<<palindrome<<endl;
        if(palindrome==x)return true;
        else return false;
    }
};

int main(){
    Solution s;
    
    cout<< s.isPalindrome(123)<<endl;
    cout<< s.isPalindrome(121)<<endl;
    cout<< s.isPalindrome(-121)<<endl;
}