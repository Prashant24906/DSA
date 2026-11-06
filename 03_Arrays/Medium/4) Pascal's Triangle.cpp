class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row = 0;row<numRows;row++){
            vector<int> temp;
            for(int col= 0;col<=row;col++){
                if(col==0||col==row||row==0){
                    temp.push_back(1);
                }
                else{
                    temp.push_back(ans[row-1][col]+ans[row-1][col-1]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
