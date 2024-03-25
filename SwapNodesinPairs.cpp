 /*--------------------------------------------
 INPUT: Given a linked list
 OUTPUT: Swap every two adjacent nodes and return its head
 ALGORITHM: 
 ---------------------------------------------*/
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* now = head;
        while(now != NULL) {
            if(now->next != NULL) { //pair
                int temp = now->val;
                now->val = now->next->val;
                now->next->val = temp;

                now = now->next->next;
            }
            else break;

        }
        return head;
    }
};