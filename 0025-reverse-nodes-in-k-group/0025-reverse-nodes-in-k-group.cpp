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
    ListNode* newHead = reverse(temp->next);
    ListNode* front = temp->next;
    front->next = temp;
    temp->next = NULL;
    return newHead; 
 }

 ListNode* findk(ListNode* temp, int k){
    k = k-1;
    while(temp!=NULL && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
 }


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next == NULL){
            return head;
        }

        
        ListNode* temp = head;
        ListNode* nextNode = NULL;
        ListNode* prevNode = NULL;

        while(temp != NULL){
            ListNode* knode = findk(temp,k);
            if(knode == NULL){
                if(prevNode){
                    prevNode->next = temp;
                }
                break;
            }
            nextNode = knode->next;
            knode->next = NULL;
            ListNode* newHead = reverse(temp);
            if(temp == head){
                head = knode;
            }
            else{
                prevNode->next = knode;
            }

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};