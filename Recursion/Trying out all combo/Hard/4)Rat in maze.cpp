class Solution {
  public:
    void helper(vector<string> &ans,vector<vector<int>>& maze,int row,int col,string temp){
        if(row>=maze.size()||col>=maze.size()||maze[row][col]!=1||row<0||col<0){
            return ;
        }
        if(row==maze.size()-1&&col==maze.size()-1){
            ans.push_back(temp);
            return ;
        }
        if(maze[row][col]==1){
            maze[row][col] = 0;
            helper(ans,maze,row+1,col,temp+'D');
            helper(ans,maze,row,col-1,temp+'L');
            helper(ans,maze,row,col+1,temp+'R');
            helper(ans,maze,row-1,col,temp+'U');
            maze[row][col] = 1;
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        helper(ans,maze,0,0,"");
        return ans;
    }
};