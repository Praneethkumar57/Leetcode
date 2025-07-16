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

 ListNode* reverse(ListNode* temp, int left, int right){
    if(left == right){
        return temp;
    }
    ListNode* newHead = reverse(temp->next, left+1,right);
    ListNode* front = temp->next;
    temp->next = temp->next->next;
    front->next = temp;
    return newHead;
 }


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL || left == right){
            return head;
        }

        if(left == 1){
            ListNode* temp = head;
            ListNode* newhead = reverse(temp,left,right);
            return newhead;
        }


        ListNode* prev = NULL;
        ListNode* temp = head;
        for(int i=1;i<left;i++){
            prev = temp;
            temp = temp->next;
        }
        
        ListNode* newhead = reverse(temp,left,right);
        prev->next = newhead;
        return head;
    }
};