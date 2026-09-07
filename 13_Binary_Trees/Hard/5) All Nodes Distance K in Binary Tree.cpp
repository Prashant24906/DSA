/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        // Store the parent in hashmap
        unordered_map<TreeNode*,TreeNode*> parents;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left){
                    parents[node->left] = node;
                    q.push(node->left);
                }

                if (node->right){
                    parents[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        //Traverse in the map and queue
        unordered_map<TreeNode*,int> visited;
        int distance = 0;
        q.push(target);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                visited[node]++;
                if(distance==k){
                    ans.push_back(node->val);
                }
                if (node->left&&visited.find(node->left)==visited.end()){
                    q.push(node->left);
                    visited[node->left]++;
                }
                if (node->right&&visited.find(node->right)==visited.end()){
                    q.push(node->right);
                    visited[node->right]++;
                }
                if(parents.find(node)!=parents.end()&&visited.find(parents[node])==visited.end()){
                    q.push(parents[node]);
                    visited[parents[node]]++;
                }
            }
            distance++;
        }
        return ans;
    }
};
