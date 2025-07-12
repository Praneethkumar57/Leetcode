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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        int sum=0, carry =0;
        while(temp1 != NULL || temp2 != NULL){
            sum = carry;
            if(temp1){
                sum = sum + temp1->val;
                temp1 = temp1->next;
            }
            if(temp2){
                sum = sum + temp2->val;
                temp2 = temp2->next;
            }

            ListNode* x = new ListNode(sum%10);
            current->next = x;
            current = x;

            carry = sum/10;
        }

        if(carry){
            ListNode* x = new ListNode(carry);
            current->next = x;
        }

        return(dummy->next);
        
    }
};