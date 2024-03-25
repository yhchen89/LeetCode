/*--------------------------------------------------------------------------------------
INPUT: two sorted linked lists
OUTPUT: a merged sorted list
ALGORITHM: compare the element in l1 and l2, push the smaller one in the mergedList, the 
pointer point to the smaller list's next, until one of the list point to the nullptr and
 push the list which is not point to the nullptr in the mergedlist and return
---------------------------------------------------------------------------------------*/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* mergedList = NULL;
        ListNode* head = mergedList;

        while(l1 != NULL && l2 != NULL){
            ListNode* newNode = new ListNode();
            if(l1->val >= l2->val) {
                newNode->val = l2->val;
                l2 = l2->next;
            }
            else {
                newNode->val = l1->val;
                l1 = l1->next;
            }

            if(mergedList == NULL) {
                mergedList = newNode;
                head = newNode;
            }
            else {
                mergedList->next = newNode;
                mergedList = mergedList->next;
            }
            //delete newNode;
        }
        if(l1 != NULL) {
            if(mergedList == NULL) {
                mergedList = l1;
                head = mergedList;
            }
                
            else mergedList->next = l1;
        }
        else if(l2 != NULL){
            if(mergedList == NULL) {
                mergedList = l2;
                head = mergedList;
            }
                
            else mergedList->next = l2;
        }
        
        return head;
    }
};

int main(){
    /*Solution s;
    ListNode* ans = s.mergeTwoLists(l1, l2);
    while(ans->next!=NULL){
        cout<<ans->val<<endl;
        ans = ans->next;
    }*/
}