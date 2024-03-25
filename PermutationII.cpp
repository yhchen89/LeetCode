/*-------------------------------------
HINT: 
void permute(list, i, n) {
    if(i==n){
        for(j=1;j<=n;j++)
            print list[j]
    }
    else {
        for(j=i;j<=n;j++) {
            swap(list[i], list[j]);
            permute(list, i+1, n);
            swap(list[i], list[j]);
        }
    }
}
--------------------------------------*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    map<vector<int>, bool> isDuplicate;
    int n;
    void swap(vector<int>& nums, int index, int i) {
        int temp = nums[index];
        nums[index] = nums[i];
        nums[i] = temp;
    }
    void generate(vector<int>& nums, int index) {
        if(index == n - 1) {
            if(!isDuplicate[nums])
                result.push_back(nums);
                isDuplicate[nums] = true;
        }
        else {
            for(int i = index; i < n; i++) {
                swap(nums, index, i);
                generate(nums, index + 1);
                swap(nums, index, i);
            }
            //return nums;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        generate(nums, 0);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 2};
    s.permuteUnique(nums);
    //cout<<nums.size();
    //for(int i = 0; i < 6; i++) {
    //    for(int j = 0; j < nums.size(); j++)
    //        cout<<s.permuteUnique(nums)[i][j];
    //    cout<<endl;
    //}
    
}