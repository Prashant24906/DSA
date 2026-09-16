class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return {};
        TreeNode* cur = root;
        while(cur){
            if(!cur->left){
                res.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* prev = cur->left;
                while(prev->right&&prev->right!=cur)
                    prev = prev->right;
                if(prev->right==cur){
                    prev->right = nullptr;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
                else{
                    prev->right = cur;
                    cur = cur->left;
                }
            }
        }
        return res;        
    }
};
