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

 int find(vector<int>& arr, int val){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==val){
            return 1;
        }
    }
    return 0;
 }

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        vector<int> arr;
        ListNode* temp = head;
        while(temp->next != NULL){
            if(temp->val == temp->next->val){
                arr.push_back(temp->val);
            }
            temp = temp->next;
        }

        temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            if(find(arr,temp->val)==1){
                if(temp == head){
                    head = head->next;
                    temp = head;
                }
                else{
                    prev->next = temp->next;
                    temp = temp->next;
                }
            }
            else{
                prev = temp;
                temp = temp->next;
            }     
        }
        return head;
    }
};