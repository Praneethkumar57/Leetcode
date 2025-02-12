/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* temp1,*temp2,*temp,*head;
    head = NULL;
    temp1 = list1;
    temp2 = list2;
    if(temp1==NULL){
        return list2;
    }
    if(temp2==NULL){
        return list1;
    }
    while(temp1 != NULL && temp2 != NULL){
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(temp1->val < temp2->val){
            node->val = temp1->val;
            node->next = NULL;
            temp1 = temp1->next;
        }
        else{
            node->val = temp2->val;
            node->next = NULL;
            temp2 = temp2->next;
        }
        if(head == NULL){
            head = node;
            temp = head;
        }
        else{
            temp->next = node;
            temp = temp->next;
        }
    }
    printf("%d",temp->val);
    while(temp1 != NULL){
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = temp1->val;
        node->next = NULL;
        temp->next = node;
        temp = temp->next;
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = temp2->val;
        node->next = NULL;
        temp->next = node;
        temp = temp->next;
        temp2 = temp2->next;
    }
    return head;
}