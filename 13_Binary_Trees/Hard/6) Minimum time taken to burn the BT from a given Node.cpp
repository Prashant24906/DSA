class Solution {
  public:
      int TimeToBurn(Node* root,int k) {
        Node* target = nullptr;
        // Store the parent in hashmap
        unordered_map<Node*,Node*> parents;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                Node* node = q.front();
                q.pop();
                if(node->data == k) target = node;
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
        int time = 0;
        unordered_map<Node*,int> visited;
        q.push(target);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                Node* node = q.front();
                q.pop();
                visited[node]++;
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
            time++;
        }
        return time;
    }
    int minTime(Node* root, int target) {
        return TimeToBurn(root,target)-1;
        
    }
};
