#include<iostream>
using namespace std;
/*
INPUT: a roman numeral
OUTPUT: convert it to an integer
*/

class Solution {
public:
    int romanToInt(string s) {
        int index=0;
        int value=0;
        int result=0;
        bool jump=false;
        while(s[index]!='\0'){
            switch(s[index]){
                case 'I':
                    if(s[index+1]=='V'){
                        value=4;
                        jump=true;
                    }
                    else if(s[index+1]=='X'){
                        value=9;
                        jump=true;
                    }
                    else value=1;
                    break;
                case 'V':
                    value=5;
                    break;
                case 'X':
                    if(s[index+1]=='L'){
                        value=40;
                        jump=true;
                    }
                    else if(s[index+1]=='C'){
                        value=90;
                        jump=true;
                    }
                    else value=10;
                    break;
                case 'L':
                    value=50;
                    break;
                case 'C':
                    if(s[index+1]=='D'){
                        value=400;
                        jump=true;
                    }
                    else if(s[index+1]=='M'){
                        value=900;
                        jump=true;
                    }
                    else value=100;
                    break;
                case 'D':
                    value=500;
                    break;
                case 'M':
                    value=1000;
                    break;
            }
            result=result+value;
            if(jump){
                index=index+2;
                jump=false;
            }
            else
                index++;
        }
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.romanToInt("MCMXCIV");
}