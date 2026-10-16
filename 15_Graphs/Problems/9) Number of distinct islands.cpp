class Solution {
  public:
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,set<vector<pair<int,int>>>& st,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        q.push({i,j});
        vis[i][j] = true;
        pair<int,int> base = {i,j};
        vector<pair<int,int>> temp;
        temp.push_back({0,0});
        while(!q.empty()){
            pair<int,int> Element = q.front();
            q.pop();
            
            for(int i = 0;i<4;i++){
                int nrow = Element.first + drow[i];
                int ncol = Element.second + dcol[i];
                
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&grid[nrow][ncol]=='L'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = true;
                    int row = nrow - base.first;
                    int col = ncol - base.second;
                    temp.push_back({row,col});
                }
            }
        }
        st.insert(temp);
    }
    int countDistinctIslands(vector<vector<char>>& grid) {
        // Variable initialization
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        set<vector<pair<int,int>>> st;
        int distinctIslands = 0;
        
        // Solve
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 'L'&&!vis[i][j]){
                    bfs(grid,vis,st,i,j);
                }
            }
        }
        return st.size();
    }
};
