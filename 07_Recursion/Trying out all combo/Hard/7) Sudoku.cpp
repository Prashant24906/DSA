class Solution {
public:
    //We use loops when we need to TRY multiple choices.
    // We use recursion when we simply need to MOVE forward.
    bool check(vector<vector<char>>& board,int row,int col){
        char ch = board[row][col];
        //Check in row;
        for(int i = 0;i<9;i++){
            if(board[i][col]==ch){
                if(i==row) continue;
                else return false;
            }
        }//Check in coloumn;
        for(int i = 0;i<9;i++){
            if(board[row][i]==ch){
                if(i==col) continue;
                else return false;
            } 
        }
        //Check the 3x3 sub-box;
        for(int i = (row/3)*3;i<((row/3)*3)+3;i++){
            for(int j = (col/3)*3;j<((col/3)*3)+3;j++){
                if(row==i&&col==j) continue;
                if(board[i][j]==ch) return false;
            }
        }
        //If not found the return true;
        return true;
    }
    bool helper(vector<vector<char>>& board,int row,int col){
        //if we have reached the last cells then return 
        if(row==9){
            return true;
        }
        //if its a number skip the cell
        if(board[row][col]!='.'){
            if(col==8) return helper(board,row+1,0);
            else return helper(board,row,col+1);
        }
        else{
            for(int k = 1;k<10;k++){
                //store the character
                char ch = k + '0';
                board[row][col] = ch;
                //check is possible to put the character in that cell
                bool possible = check(board,row,col);
                if(possible){
                if(col==8){
                    if(helper(board,row+1,0)) return true;
                } 
                else if(helper(board,row,col+1)) return true;
                }
                //backtrack
                board[row][col] =  '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};
