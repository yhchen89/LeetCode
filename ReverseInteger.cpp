#include <iostream>
#include<climits>
#include <string>
#include<cstdlib>
using namespace std;

/*
INPUT: a signed 32-bit integer x
ALGORITHM: 轉換成字串輸出
OUTPUT:　x with its digits reversed
NOTICE:  If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0
*/

class Solution{
public:
    int reverse(int x){
        if(x==0)
            return 0;

        string sign;
        string result;

        //將負數轉換為正數
        if (x < 0){
            sign = "-";
            //x = x * -1; //INT_MIN*-1會發生overflow
        }

        //將轉換後最高位為0的去除
        for (x; x % 10 == 0; x = x / 10){}

        //整數轉成字串
        for (x; x != 0; x = x / 10){
            if(x%10<0)
                result = result + to_string(x % 10*-1);
            else
                result = result + to_string(x % 10);
        }

        result = sign + result;
        //cout << result.c_str() << endl;

        //字串轉整數
        /*
        LIB: cstdlib
        atoi -> 將char陣列轉換成整數
        c_str -> 將string轉換成char陣列
        */

        //轉換後發生overflow則return 0
        long long int ret=atoll(result.c_str());
        if(ret>INT_MAX|ret<INT_MIN)return 0;
        else return ret;
    }
};

int main(){
    Solution s;
    cout<<s.reverse(-123);
}