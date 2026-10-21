class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int>& color,int node){
        int n = graph.size();
        queue<int> q;
        
        q.push(node);
        color[node] = 1;

        while(!q.empty()){
            int CurrentNode = q.front();
            int NodeColor = color[CurrentNode];
            q.pop();

            for(auto adjNode: graph[CurrentNode]){
                if(color[adjNode]==-1){
                    color[adjNode] = NodeColor==1?0:1;
                    q.push(adjNode);
                }
                else if(color[adjNode]==color[CurrentNode]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i = 0;i<n;i++){
            if(color[i] == -1){
                bool check = bfs(graph,color,i);
                if(!check) return false;
            }
        }
        return true;
    }
};
