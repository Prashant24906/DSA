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
    int HeightOfLeftTree(TreeNode* root,int h){
        if(!root) return h;
        return HeightOfLeftTree(root->left,h+1);
    }
    int HeightOfRightTree(TreeNode* root,int h){
        if(!root) return h;
        return HeightOfRightTree(root->right,h+1);
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = HeightOfLeftTree(root,0);
        int rh = HeightOfRightTree(root,0);
        if(lh==rh) return (1<<lh)-1;
        return 1 + countNodes(root->left)+ countNodes(root->right);
    }
};
