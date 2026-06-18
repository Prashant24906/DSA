class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int candidate = 0;
        for(int i =1;i<mat.size();i++){
            if(mat[candidate][i] == 1){
                candidate = i;
            }
        }
        int cnt = 0;
        for(int i = 0;i<mat.size();i++){
            if(i == candidate ) continue;
            if(mat[candidate][i]== 1) return -1;
            if(mat[i][candidate]== 0) return -1;
        }
        return candidate;
        
    }
};
