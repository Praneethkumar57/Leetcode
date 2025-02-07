/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* p = head;
    struct ListNode* prev = head;
    int i =1;
    int count = 0;
    while(p != NULL){
        count ++;
        p = p->next;
    }
    p = head;
    if(count <=0){
        return head;
    }
    if(count == 1 && n==1){
        head = NULL;
        return head;
    }
    else if(count==1 && n==0){
        return head;
    }
    else{
        int val = count-n + 1;
        if(val == 1){
            p = p->next;
            head = p;
            return head;
        }
        else{
            while(i<val){
                prev = p;
                p = p->next;
                i = i+1;
            }
            
            if(p->next != NULL){
                prev->next= p->next;
                p->next = NULL;
                p = NULL;
            }
            else{
                prev->next = NULL;
                p = NULL;
            }
            return head;

        }
        
    }
   
}