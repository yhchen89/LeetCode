#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int *returnArr;
    for(int i=0; i<numsSize; i++){
        int x=nums[i];
        for(int j=0; j<numsSize&&j!=i; j++){
            int y=nums[j];
            for(int k=0; k<numsSize&&k!=i&&k!=j; k++){
                int z=nums[k];
                if(x+y+z==0){
                    returnArr = realloc(returnArr, 3*sizeof(int));
                }
                    

            }
        }
    }
}

int main(){
    int *nums;
    int numsSize = 6;
    nums = malloc(numsSize*sizeof(int));
    if(nums==NULL){
        printf("error");
        return 1;
    }
    int returnAns[2][3]={0};
    threeSum(nums, numsSize, )
    free(nums);
    return 0;
}