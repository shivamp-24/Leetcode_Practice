/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        else if(!list2) return list1;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* curr;
        if(temp1->val<temp2->val){
            curr=temp1;
            temp1=temp1->next;
        }
        else{
            curr=temp2;
            temp2=temp2->next;
        }
        ListNode* head=curr;
        while(temp1 && temp2){
            if(temp1->val<temp2->val){
                curr->next=temp1;
                temp1=temp1->next;
            }
            else{
                curr->next=temp2;
                temp2=temp2->next;
            }
            curr=curr->next;
        }
        if(temp1) curr->next=temp1;
        else curr->next=temp2;
        return head;
    }
};