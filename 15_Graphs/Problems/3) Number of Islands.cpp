class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i,
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
                    !visited[nrow][ncol] && grid[nrow][ncol] == '1') {
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    bfs(grid, visited, i, j);
                }
            }
        }
        return islands;
    }
};
