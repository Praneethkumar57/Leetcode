/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        queue<pair<Node*,int>> q;
        int depth=1;
        if(root==NULL)return 0;
        q.push({root,1});
        
        while(!q.empty()){
            pair<Node*,int> ele=q.front();
            Node* node=ele.first;
            int t=ele.second;
            depth = max(depth,t);
            q.pop();
            for(auto it:node->children){
                q.push({it,t+1});
            }
        }
        return depth;
    }
};