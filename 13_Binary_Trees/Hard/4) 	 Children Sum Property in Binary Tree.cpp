/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        if(!root||(!root->left&&!root->right)) return true;
        int leftChildVal = root->left?root->left->data:0;
        int rightChildVal = root->right?root->right->data:0;
        return isSumProperty(root->left)&&isSumProperty(root->right)&&root->data==rightChildVal+leftChildVal;
    }
};
