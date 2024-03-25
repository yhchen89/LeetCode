/*----------------------------------------------------------------------
INPUT: Given a sorted array of distinct integers and a target value
OUTPUT: return the index if the target is found.If not, return 
        the index where it would be if it were inserted in order
ALGORITHM: Binary Search
----------------------------------------------------------------------*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int targetIndex;

        while(left <= right) {
            targetIndex = (left + right) / 2;
            if (nums[targetIndex] == target)
                return targetIndex;
            else {
                if(target > nums[targetIndex])
                    left = targetIndex + 1;
                else 
                    right = targetIndex - 1;
            }
        }

        if(target > nums[targetIndex])
            return targetIndex + 1;
        else 
            return targetIndex;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);
    //nums.push_back(3);
    //nums.push_back(5);
    //nums.push_back(6);
    int target = 0;
    Solution s;
    cout<<s.searchInsert(nums, target);
}