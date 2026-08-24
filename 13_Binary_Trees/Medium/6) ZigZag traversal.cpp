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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*> level;
        bool leftToRight = true;
        if(root)
            level.push(root);
        while(!level.empty()){
            int size = level.size();
            vector<int> temp(size,-1);
            for(int i = 0;i<size;i++){
                TreeNode* node = level.front();
                level.pop();
                if(leftToRight) temp[i] = node->val;
                else temp[size-i-1] = node->val;
                if(node->left)
                    level.push(node->left);
                if(node->right)
                    level.push(node->right);
            }
            ans.push_back(temp);
            leftToRight = !leftToRight;
        }
        return ans;

    }
};
