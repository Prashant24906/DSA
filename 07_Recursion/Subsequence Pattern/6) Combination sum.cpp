class Solution {
public:
    void helper(vector<int>& candidates,vector<vector<int>>& ans,int target,int sum,int index,vector<int>& temp){  
        if(sum==target){
            ans.push_back(temp);
            return ;
        }
        if(index==candidates.size()||sum>target){
            return ;
        }
        temp.push_back(candidates[index]);
        helper(candidates,ans,target,sum+candidates[index],index,temp);
        temp.pop_back();
        helper(candidates,ans,target,sum,index+1,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(candidates,ans,target,0,0,temp);
        return ans;
    }
};