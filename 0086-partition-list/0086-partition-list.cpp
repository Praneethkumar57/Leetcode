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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp1=dummy;
        ListNode* temp=head;
        ListNode* great=NULL;
        while(temp){
            if(temp->val>=x){
                great = temp;
                break;
            }
            temp1->next=temp;
            temp1=temp;
            temp=temp->next;
        }
        if(great==NULL){
            return head;
        }
        ListNode* temp2=great;
        while(temp!=NULL){
            ListNode* next=temp->next;
            if(temp->val<x){
                temp1->next=temp;
                temp1=temp;
                temp->next=great;
                temp2->next=next;
            }
            else{
                temp2=temp;
            }
            temp=next;
        }
        temp1->next=great;
        return(dummy->next);
    }
};