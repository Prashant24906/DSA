class Solution {
public:
    bool vertical(vector<string>& combinations, int row, int col, int n) {
        for (int i = 0; i < n; i++) {
            if (combinations[i][col] == 'Q')
                return true;
        }
        return false;
    }
    bool Horizontal(vector<string>& combinations, int row, int col, int n) {
        for (int i = 0; i < n; i++) {
            if (combinations[row][i] == 'Q')
                return true;
        }
        return false;
    }
    bool crossRight(vector<string>& combinations, int row, int col, int n) {
        int i = row;
        int j = col;
        while (i >= 0 && j >= 0) {
            if (combinations[i][j] == 'Q')
                return true;
            i--;
            j--;
        }
        i = row;
        j = col;
        while (i < n && j < n) {
            if (combinations[i][j] == 'Q')
                return true;
            i++;
            j++;
        }
        return false;
    }
    bool crossLeft(vector<string>& combinations, int row, int col, int n) {
        int i = row;
        int j = col;
        while (i >= 0 && j < n) {
            if (combinations[i][j] == 'Q')
                return true;
            i--;
            j++;
        }
        i = row;
        j = col;
        while (i < n && j >= 0) {
            if (combinations[i][j] == 'Q')
                return true;
            i++;
            j--;
        }
        return false;
    }
    void helper(vector<vector<string>>& Queens, vector<string>& combinations,
                int row, int col, int QueensPlaced, int n) {
        if (n == QueensPlaced) {
            Queens.push_back(combinations);
            return;
        }
        if (col >= n || row >= n)
            return;
        for (int i = col; i < n; i++) {
            bool possible = Horizontal(combinations, row, i, n) ||
                            vertical(combinations, row, i, n) ||
                            crossRight(combinations, row, i, n) ||
                            crossLeft(combinations, row, i, n);
            if (!possible) {
                combinations[row][i] = 'Q';
                helper(Queens, combinations, row + 1, 0, QueensPlaced + 1, n);
                combinations[row][i] = '.';
            }
        }

        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        string t = "";
        for (int j = 0; j < n; j++) {
            t += '.';
        }
        for (int i = 0; i < n; i++) {
            temp.push_back(t);
        }
        helper(ans, temp, 0, 0, 0, n);
        return ans;
    }
};