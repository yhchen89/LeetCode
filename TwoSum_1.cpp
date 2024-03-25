//map
#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>m;
        map<int, int>::iterator it;
        vector<int> answer;
        for(int i=0;i<nums.size();i++){
            m[target-nums.at(i)]=i;
        }
        for(int i=0;i<nums.size();i++){
            it = m.find(nums.at(i));
            if(it->second==i)continue;
            if(it!=m.end()){
                answer.push_back(i);
                answer.push_back(it->second);
               
                return answer;
            }
        }
        throw("no solution");
    }
};

int main(){
    return 0;
}