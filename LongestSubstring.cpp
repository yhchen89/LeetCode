/*-----------------------------------------
INPUT: a string s
OUTPUT: the length of the longest substring
NOTICE: without repeating characters.
-------------------------------------------*/
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> record;                   //紀錄是否遇到重複的字元
        int index = 0;                           //目前處理到的字元索引   
        int length = 0;                          //目前子字串長度
        int MaxLength = 0;                       //最長子字串長度

        while(s[index] != '\0'){
            if(record[s[index]] != '\0'){        //如果字元重複出現
                if(length>MaxLength)
                    MaxLength=length;
                int past = record[s[index]] - 1;    //紀錄重複字元之前的索引
                //cout<<"index"<<index<<"past"<<past<<endl;
                record.clear();
                length=0;
                while(past != index){               //從重複字元之前索引開始重新記錄(可改進)
                    record[s[past]] = past + 1;
                    length++;
                    past++;
                }
                record[s[index]] = index + 1;       
            }
            else{
                record[s[index]] = index + 1;
                length++;
                if(length>MaxLength)
                    MaxLength=length;
            }
            //cout<<s[index]<<length<<endl;
            index++;
        }

        return MaxLength;
    }
};

//HINT:用map的值紀錄索引，須注意所引為0，因為索引為0 map視為空值

int main(){
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") <<endl;    //3
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;      //1
    cout << s.lengthOfLongestSubstring("pwwkew") <<endl;      //3
    cout << s.lengthOfLongestSubstring("dvdf") <<endl;        //3
    cout << s.lengthOfLongestSubstring("ckilbkd") <<endl;     //5
    cout << s.lengthOfLongestSubstring("tmmzuxt") <<endl;     //5
    cout << s.lengthOfLongestSubstring(" ");                  //1
}