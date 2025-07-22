/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while(temp!=NULL){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        temp = head;
        while(temp != NULL){
            Node* randomNode = temp->next;
            if(temp->random != NULL){
                randomNode->random = temp->random->next;
            }
            else{
                randomNode->random = NULL;
            }
            temp = temp->next->next;
        }

        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp = head;
        while(temp != NULL){
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};