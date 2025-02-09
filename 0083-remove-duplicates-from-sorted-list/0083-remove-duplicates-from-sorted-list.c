/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* temp;
    struct ListNode* p;
    temp = head;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->val == temp->next->val){
            p = temp->next;
            temp->next = p->next;
            p = NULL;
            free(p);
        }
        else{
            temp = temp->next;
        }
        
    }
    return head;
}