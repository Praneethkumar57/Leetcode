/**
 * Definition for singly-linked list.
 *struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* temp1,*temp2,*head,*temp;
    temp1 = l1;
    temp2 = l2;
    int val,sum,rem=0;
    head = NULL;
    while(temp1!=NULL && temp2!=NULL){
        sum = temp1->val + temp2->val + rem;
        val = sum%10;
        rem = sum/10;
        struct ListNode* node = (struct ListNode*)(malloc)(sizeof(struct ListNode));
        node->val = val;
        node->next = NULL;
        if(head == NULL){
            head = node;
            temp = head;
        }
        else{
            temp->next = node;
            temp = temp->next;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while(temp1!=NULL){
        sum = temp1->val + rem;
        val = sum%10;
        rem = sum/10;
        struct ListNode* node = (struct ListNode*)(malloc)(sizeof(struct ListNode));
        node->val = val;
        node->next = NULL;
        temp->next = node;
        temp = temp->next;
        temp1 = temp1->next;
    }
    while(temp2!=NULL){
        sum = temp2->val + rem;
        val = sum%10;
        rem = sum/10;
        struct ListNode* node = (struct ListNode*)(malloc)(sizeof(struct ListNode));
        node->val = val;
        node->next = NULL;
        temp->next = node;
        temp = temp->next;
        temp2 = temp2->next;
    }
    if(rem!=0){
        struct ListNode* node = (struct ListNode*)(malloc)(sizeof(struct ListNode));
        node->val = rem;
        node->next = NULL;
        temp->next = node;
    }
    return head;
}