/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void helper(Node* root,vector<vector<int>>& ans,vector<int> temp){
        if(!root->left&&!root->right){
            temp.push_back(root->data);
            ans.push_back(temp);
            return ;
        }
        if(root->left){
            temp.push_back(root->data);
            helper(root->left,ans,temp);
            temp.pop_back();
        }
        if(root->right){
            temp.push_back(root->data);
            helper(root->right,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> paths(Node* root) {
        vector<vector<int>> ans;
        helper(root,ans,{});
        return ans;
    }
};
