class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,
             int j) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        visited[i][j] = true;
        q.push({i, j});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = temp.first + drow[i];
                int ncol = temp.second + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        // 1. Sink land connected to left and right boundaries
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) bfs(grid,visited,i, 0);
            if (grid[i][m - 1] == 1) bfs(grid,visited,i, m - 1);
        }

        // 2. Sink land connected to top and bottom boundaries
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) bfs(grid,visited,0, j);
            if (grid[n - 1][j] == 1) bfs(grid,visited,n - 1, j);
        }
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
