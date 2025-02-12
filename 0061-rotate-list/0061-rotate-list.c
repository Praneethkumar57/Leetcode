/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* rotate(struct ListNode* head){
    struct ListNode* temp=head;
    struct ListNode* prev;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    temp->next = head;
    head = temp;
    prev->next = NULL;
    return head;
 }
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int i=0,rem,len;
    len =0;
    struct ListNode* temp=head;
    if(head == NULL || head->next == NULL){
        return head;
    }
    while(temp!=NULL){
        len = len+1;
        temp = temp->next;
    }
    rem = k%len;
    for(i;i<rem;i++){
        head = rotate(head);
    }
    return head;
}