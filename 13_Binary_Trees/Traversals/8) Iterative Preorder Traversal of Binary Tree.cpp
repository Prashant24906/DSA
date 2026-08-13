/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        while(root){
            if(root->right)
                st.push(root->right);
            ans.push_back(root->val);
            cout<<root->val<<endl;
            root = root->left;
            if(!root)
                if(!st.empty()){
                    root = st.top();
                    st.pop();
                }
        }
        return ans;
    }
};
