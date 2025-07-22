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

 ListNode* merge(ListNode* list1, ListNode* list2){
    ListNode* dummy = new ListNode(-1);
    ListNode* res = dummy;
    while(list1!=NULL && list2!=NULL){
        if(list1->val <= list2->val){
            res->next = list1;
            list1 = list1->next;
        }
        else{
            res->next = list2;
            list2 = list2->next;
        }
        res = res->next;
    }
    if(list1){
        res->next = list1;
    }
    else{
        res->next = list2;
    }
    return dummy->next;
 }

 ListNode* fun(vector<ListNode*>& lists, int n){
    if(n == lists.size()-1){
        return lists[n];
    }
    ListNode* mergehead = fun(lists, n+1);
    ListNode* newhead = merge(lists[n], mergehead);
    return newhead;
 }

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        return fun(lists,0);
    }
};