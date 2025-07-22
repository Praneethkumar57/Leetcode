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

 ListNode* findmiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
 }

 ListNode* merge(ListNode* lefthead, ListNode* righthead){
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    while(lefthead != NULL && righthead != NULL){
        if(lefthead->val <= righthead->val){
            temp->next = lefthead;
            temp = lefthead;
            lefthead = lefthead->next;
        }
        else{
            temp->next = righthead;
            temp = righthead;
            righthead = righthead->next;
        }
    }
    if(lefthead){
        temp->next = lefthead;
    }
    else{
        temp->next = righthead;
    }

    return dummy->next;
 }

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* middle = findmiddle(head);
        ListNode* lefthead = head;
        ListNode* righthead = middle->next;
        middle->next = NULL;
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);
        return merge(lefthead,righthead);
    }
};