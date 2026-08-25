/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int data) {
        data = data;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void rightMost(Node* root,vector<int>& ans){
        if(!root) return ;
        if(!root->left&&!root->right) return ;
        rightMost(root->right,ans);
        if(!root->right)
            rightMost(root->left,ans);
        ans.push_back(root->data);
    }
    void Leafs(Node* root,vector<int>& ans){
        if(!root) return ;
        Leafs(root->left,ans);
        if(!root->left&&!root->right)
            ans.push_back(root->data);
        Leafs(root->right,ans);
    }
    void leftMost(Node* root,vector<int>& ans){
        if(!root) return ;
        if(!root->left&&!root->right) return ;
        ans.push_back(root->data);
        leftMost(root->left,ans);
        if(!root->left)
            leftMost(root->right,ans);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(root)
            ans.push_back(root->data);
        if(!root->right&&!root->left) return ans;
        leftMost(root->left,ans);
        Leafs(root,ans);
        rightMost(root->right,ans);
        return ans;
    }
};
