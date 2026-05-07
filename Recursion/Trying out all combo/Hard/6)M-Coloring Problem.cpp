class Solution {
    bool is_safe(int node, int col, vector<int> adj[], vector<int> &colour){
        for(auto i: adj[node]){
            if(colour[i]==col){
                return false;
            }
        }
        return 1;
    }
    private:
    bool get_ans(int node, int v, vector<int> adj[], int m, vector<int> &colour){
        if(node==v){
            return 1;
        }
        for(int i=1; i<=m; i++){
            if(is_safe(node, i, adj, colour)){
                colour[node]= i;
                if(get_ans(node+1, v, adj, m, colour)){
                    return true;
                }
                colour[node]=0;
            }
            
        }
        return false;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
       vector<int> colour(v, 0);
       vector<int> adj[v];
       for(auto i: edges){
           int u= i[0];
           int v= i[1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       
       return get_ans(0, v,adj,m, colour);
    }
};
