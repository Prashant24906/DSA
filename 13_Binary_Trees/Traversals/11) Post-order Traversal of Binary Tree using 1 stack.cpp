class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        while (root != nullptr || !stack.empty()) {
            if (root != nullptr) {
                res.push_back(root->val);
                stack.push(root);
                root = root->right;
            }
            else{
                root = stack.top();
                stack.pop();
                root = root->left;
            }
        }
        reverse(res.begin(),res.end());
        return res;        
    }
};
