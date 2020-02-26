//1.if(!root)
//2.don't s.push(root)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        stack<Node*>s;
        if(!root)
            return root;
        Node *dummy=new Node(0);
        Node *pre=dummy;
        while(root||!s.empty())
        {
            while(root)
            {
                s.push(root);
                root=root->left;   
            }
            root=s.top();
            s.pop();
            pre->right=root;
            root->left=pre;
            pre=root;
            root=root->right;
        }
        pre->right=dummy->right;
        dummy->right->left=pre;
        return dummy->right;    
    }
};