/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    stack<TreeNode*> Next;
    stack<TreeNode*> Previous;
    void initialize(TreeNode* root) {
        TreeNode* temp = root;
        while (temp) {
            Next.push(temp);
            temp = temp->left;
        }
        temp = root;
        while (temp) {
            Previous.push(temp);
            temp = temp->right;
        }
    }
    TreeNode* next() {
        TreeNode* temp = Next.top();
        Next.pop();
        TreeNode* mover = temp->right;
        while (mover) {
            Next.push(mover);
            mover = mover->left;
        }
        return temp;
    }
    TreeNode* prev(){
        TreeNode* temp = Previous.top();
        Previous.pop();
        TreeNode* mover = temp->left;
        while (mover) {
            Previous.push(mover);
            mover = mover->right;
        }
        return temp;
    }
    bool findTarget(TreeNode* root, int k) {
        initialize(root);
        TreeNode* i = next();
        TreeNode* j = prev();
        while(i!=j){
            if(i->val+j->val==k) return true;
            if(i->val+j->val<k) i = next();
            else j = prev();
        }
        return false;
    }
};
