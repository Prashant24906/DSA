class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total = n*m;
        vector<int> ans(n*m);
        int startrow = 0;
        int startcol = 0;
        int endrow = n-1;
        int endcol = m-1;
        int count = 0;
        while(count<total){
            for(int i = startcol;i<=endcol&&count<total;i++){
                ans[count] = matrix[startrow][i];
                count++; 
            }
            startrow++;
            for(int i = startrow;i<=endrow&&count<total;i++){
                ans[count] = matrix[i][endcol];
                count++;
            }
            endcol--;
            for(int i = endcol;i>=startcol&&count<total;i--){
                ans[count] = matrix[endrow][i];
                count++;
            }
            endrow--;
            for(int i = endrow;i>=startrow&&count<total;i--){
                ans[count] = matrix[i][startcol];
                count++;
            }
            startcol++;
        }
        return ans;
    }
};
