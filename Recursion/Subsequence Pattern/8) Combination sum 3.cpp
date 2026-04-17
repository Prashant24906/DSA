class Solution {
public:
    void helper(vector<vector<int>> &ans,vector<int> &temp,int k,int n,int sum,int index){
        if(sum==n&&temp.size()==k){
            ans.push_back(temp);
            return; 
        }
        if(temp.size()>k||sum>n||index==10){
            return ;
        }
        temp.push_back(index);
        helper(ans,temp,k,n,sum+index,index+1);
        temp.pop_back();
        helper(ans,temp,k,n,sum,index+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(ans,temp,k,n,0,1);
        return ans;
    }
};