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
ListNode* reverse(ListNode* temp){
    if(temp == NULL || temp->next == NULL){
        return temp;
    }
    ListNode* newhead = reverse(temp->next);
    ListNode* front = temp->next;
    front->next = temp;
    temp->next = NULL;
    return newhead;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = reverse(l1);
        ListNode* temp2 = reverse(l2);

        int carry = 0;
        ListNode* dup = new ListNode(-1);
        ListNode* mover = dup;
        while(temp1!=NULL || temp2!=NULL){
            int sum = 0;
            sum = sum + carry;
            if(temp1){
                sum = sum + temp1->val;
                temp1 = temp1->next;
            } 
            if(temp2){
                sum = sum + temp2->val;
                temp2 = temp2->next;
            } 
            if(sum>=10){
                carry = 1;
            }
            else{
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum%10);
            mover->next = newNode;
            mover = newNode;
        }
        if(carry == 1){
            ListNode* newNode = new ListNode(1);
            mover->next = newNode;
            mover = newNode;
        }
        ListNode* head = reverse(dup->next);
        return head;
    }
};