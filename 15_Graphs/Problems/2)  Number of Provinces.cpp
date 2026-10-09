class Solution {
public:
    int totalProvinces = 0;
    void dfs(vector<vector<int>>& isConnected,vector<int>& visited,int node){
        visited[node] = 1;
        for(int i = 0;i<isConnected[node].size();i++){
            if(isConnected[node][i]==1&&visited[i]!=1)
                dfs(isConnected,visited,i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        for(int i = 0;i<n;i++){
            if(visited[i]==0){
                totalProvinces++;
                dfs(isConnected,visited,i);
            }
        }
        return totalProvinces;
    }
};
