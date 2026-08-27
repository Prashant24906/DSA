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
    int maxCol = INT_MIN;
    int minCol = INT_MAX;
    void helper(TreeNode* root,priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>& pq,int row,int col){
        if(!root) return ;
        maxCol = max(maxCol,col);
        minCol = min(minCol,col);
        pq.push({col,row,root->val});
        helper(root->left,pq,row+1,col-1);
        helper(root->right,pq,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        helper(root,pq,0,0);
        vector<vector<int>> ans(maxCol-minCol+1);
        int cnt = 0;
        int col = 0;
        if(!pq.empty())
            col = pq.top()[0];
        while(!pq.empty()){
            vector<int> temp = pq.top();
            if(temp[0]!=col){
                col = temp[0];
                cnt++;
            } 
            pq.pop();
            ans[cnt].push_back(temp[2]);
        }
        return ans;
    }
};
