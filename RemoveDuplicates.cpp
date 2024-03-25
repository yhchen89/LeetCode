/**/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) {

            }
            else {
                
            }
        }
        return nums.size();
    }
};

int main(){
    Solution s;
    int len = s.removeDuplicates(nums);
    for (int i = 0; i < len; i++) {
        cout<<nums[i];
    }
}