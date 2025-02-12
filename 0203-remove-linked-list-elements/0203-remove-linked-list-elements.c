/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* temp,*prev;
    temp = head;
    prev = NULL;
    while(temp != NULL){
        if(temp->val != val){
            prev = temp;
            temp = temp->next;
        }
        else{
            if(temp == head){
                head = temp->next;
                temp->next = NULL;
                temp = head;
            }
            else{
                prev->next = temp->next;
                temp = temp->next;
            }
        }
    }
    return head;
}