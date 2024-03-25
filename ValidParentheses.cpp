/*------------------------------------------------------------------------------------
INPUT: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']'
OUTPUT: determine if the input string is valid.
ALGORITHM: O(n): use stack if the target is the stack top element's pair ,pop the element
else push in the stack. Finally, if the stack is empty, return true, else return false
------------------------------------------------------------------------------------*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        
        for(int index = 0; index < s.length(); index++){
            if(myStack.empty()){
                myStack.push(s.at(index));
                continue;
            }
            if(s.at(index) == pair(myStack.top()))
                myStack.pop();
            else myStack.push(s.at(index));
        }

        if(myStack.empty())
            return true;
        else return false;
    }
    char pair(char target) {
        switch(target){
           case '(':return ')';
           case '[':return ']';
           case '{':return '}'; 
        }

        return 0;
    }
};

int main(){
    Solution s;
    cout<<s.isValid("()")<<endl;
    cout<<s.isValid("()[]{}")<<endl;
    cout<<s.isValid("([)]")<<endl;
    cout<<s.isValid("{[]}()")<<endl;
}