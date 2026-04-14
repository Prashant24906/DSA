class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return numSubseq(arr,k)>0?true:false;
        
    }
        int helper(vector<int>& nums,int target,int sum,int index){
        int ans = 0;
        if(index==nums.size()||sum>target){
            if(sum==target) return 1;
            else return 0;
        }
        sum+=nums[index];
        ans+=helper(nums,target,sum,index+1);
        sum-=nums[index];
        ans+=helper(nums,target,sum,index+1);
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        ans+=helper(nums,target,0,0);
        return ans;
    }
};