class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //Initialize variables
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> steps(n,vector<int>(m,0));

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        //Queue for row,col and steps
        queue<pair<pair<int,int>,int>> q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = true;
                    steps[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;

            q.pop();

            for(int i = 0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]){
                    q.push({{nrow,ncol},step+1});
                    vis[nrow][ncol] = true;
                    steps[nrow][ncol] = step+1;
                }
            }
        }
        return steps;
    }
};
