/*----------------------------------------------------
INPUT: given an n x n 2D matrix representing an image
OUTPUT: rotate the image by 90 degrees (clockwise)
ALGORITHM: 
O(n2)
-----------------------------------------------------*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 1)
            return;
        for(int i = 0, j = matrix.size() - 1; i <= (matrix.size() - 1) / 2; i++, j = j - 2) {
            for(int k = i; k <= i + j - 1; k++) {
                int temp = matrix[i][k];
                matrix[i][k] = matrix[matrix.size() - 1 - k][i];
                matrix[matrix.size() - 1 - k][i] = matrix[matrix.size() - 1 - i][matrix.size() - 1 - k];
                matrix[matrix.size() - 1 - i][matrix.size() - 1 - k] = matrix[k][matrix.size() - 1 - i];
                matrix[k][matrix.size() - 1 - i] = temp;
            }
        }
    }
};
