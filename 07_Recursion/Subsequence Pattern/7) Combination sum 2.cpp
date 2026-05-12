class Solution {
public:
    void helper(vector<int>& candidates,vector<vector<int>>& ans,int target,int sum,int index,vector<int>& temp){  
        if(sum==target){
            ans.push_back(temp);
            return ;
        }
        if(index==candidates.size()||target<sum){
            return ;
        }
        temp.push_back(candidates[index]);
        helper(candidates,ans,target,sum+candidates[index],index+1,temp);
        temp.pop_back();
        while(index<candidates.size()-1&&candidates[index]==candidates[index+1]) index++;
        helper(candidates,ans,target,sum,index+1,temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        helper(candidates,ans,target,0,0,temp);
        return ans;
    }
};