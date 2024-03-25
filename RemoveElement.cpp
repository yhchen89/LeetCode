/*----------------------------------------------------------------------------------------
INPUT: Given an array nums and a value
OUTPUT: return the new length that remove all instances of that value in-place
ALGORITHM: using left and right to present the vector begin and end, if left element
equal to the removal value then swap the left and right element until right less than left
, and record the length. O(n)
-----------------------------------------------------------------------------------------*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        int left = 0;
        int right = nums.size() - 1;
        int len = 0;
        while(left < right) {
            if(nums[right] == val) {
                right--;
            }
            if(nums[left] == val) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
            else { // nums[left] != val
                len++;
                left++;
            }
        }
        if(nums[left] == val)
            return len;
        else return len + 1;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(4);
    nums.push_back(2);
    int val = 2;
    Solution s;
    int len = s.removeElement(nums, val);
    cout<<len<<endl;
    for (int i = 0; i < len; i++) {
        cout<<nums[i];
    }
}