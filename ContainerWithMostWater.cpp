/*-----------------------------------------------------------------
INPUT: Given n non-negative integers a1, a2, ..., an
OUTPUT: Find two lines, which, together with the x-axis 
forms a container, such that the container contains the most water.
ALGORITHM: O(n2)
------------------------------------------------------------------*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        /* TLE
        for(int i = 0; i < height.size() - 1; i++) {
            for(int j = i + 1; j < height.size(); j++) {
                area = height[i] > height[j]?height[j] * (j - i):height[i] * (j - i);
                if(area > maxArea)
                    maxArea = area;
            }
        }*/
        int left, right;
        int i = 0, j = height.size() - 1;
        while(j > i) {
            if(height[i] > left || height[i] > right)
                left = i;
            i++;
            if(height[j] > left || height[j] > right)
                right = j;
            j++;
        }
        int maxArea = height[left] > height[right]?height[right] * (right - left):height[left] * (right - left);;
        return maxArea;
    }
};