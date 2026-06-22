class Solution {
public:
    int sum(vector<int>& nums,int goal){
        if(goal<0) return 0;
        int l = 0, sum = 0,ans = 0;
        for(int r = 0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            if(sum<=goal)ans+=(r-l+1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sum(nums,goal)-sum(nums,goal-1);
    }
};
