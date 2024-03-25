//TLE
//O(n^2)

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums.at(i)+nums.at(j)==target){
                    vector<int> answer;
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
            }
        }
        throw("no solution");
    }
};

int main(){
    int target=0;
    cin>>target;

    vector<int> nums;
    int temp=0;
    while(cin>>temp)
        nums.push_back(temp);

    Solution s;
    cout<<s.twoSum(nums, target).at(0);
    cout<<s.twoSum(nums, target).at(1);
    
    return 0;
}