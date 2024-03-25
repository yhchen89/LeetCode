//list
#include<iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer=NULL;
        ListNode* head;
        int carry=0;
        while(l1!=NULL||l2!=NULL){
            ListNode* newNode=new ListNode();
            if(l1!=NULL)
                newNode->val+=l1->val;
            if(l2!=NULL)
                newNode->val+=l2->val;
            newNode->val+=carry;
            newNode->next=NULL;
            carry=0;
            if(newNode->val>9){
                newNode->val-=10;
                carry=1;
            }
            if(answer==NULL){
                answer=newNode;
                head=answer;
            }
            else{
                while(answer->next!=NULL){
                    answer=answer->next;
                }
                answer->next=newNode;
                answer=answer->next;
            }
            if(l1!=NULL)
                l1=l1->next;
            if(l2!=NULL)
                l2=l2->next;
        }
        if(carry==1){
            ListNode* newNode=new ListNode(1);
            answer->next=newNode;
        }
        answer=head;
        return answer;
    }
}; 

//fast
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* ptr ;
        ptr = dummy;
        int carry=0;
        while(l1 && l2)
        {
            ptr->next = new ListNode();
            ptr=ptr->next;
            ptr->val = (l1->val+l2->val+carry)%10;
            carry = (l1->val+l2->val+carry)/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            ptr->next = new ListNode();
            ptr=ptr->next;
            ptr->val = (l1->val+carry)%10;
            carry = (l1->val+carry)/10;
            l1=l1->next;
        }
        while(l2)
        {
            ptr->next = new ListNode();
            ptr=ptr->next;
            ptr->val = (l2->val+carry)%10;
            carry = (l2->val+carry)/10;
            l2=l2->next;
        }
        if(carry)
        {
            ptr->next = new ListNode();
            ptr=ptr->next;
            ptr->val = carry;
        }
        ptr->next=NULL;
        return dummy->next;
    }
};
*/

int main(){
    ListNode* l1=new ListNode(5);
    ListNode* l2=new ListNode(5);

    Solution s;
    ListNode* answer;
    answer=s.addTwoNumbers(l1,l2);
    while(answer!=NULL){
        cout<<answer->val<<endl;
        answer=answer->next;
    }
    return 0;
}