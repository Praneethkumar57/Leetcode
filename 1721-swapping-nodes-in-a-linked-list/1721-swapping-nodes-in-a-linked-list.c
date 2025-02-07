/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    int val = count - k;
    int i=1;
    temp = head;
    while(i<k){
        temp = temp->next;
        i++;
    }
    int val1 = temp->val;
    struct ListNode* temp2 = head;
    i=0;
    while(i<val){
        temp2 = temp2->next;
        i++;
    }
    int val2 = temp2->val;
    temp->val = val2;
    temp2->val = val1;
    return head;
}