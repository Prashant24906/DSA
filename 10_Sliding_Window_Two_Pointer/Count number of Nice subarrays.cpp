class Solution {
public:
    int sum(vector<int>& nums,int goal){
        if(goal<0) return 0;
        int l = 0, odd = 0,ans = 0;
        for(int r = 0;r<nums.size();r++){
            if((nums[r]&1)==1) odd++;
            while(odd>goal){
                if((nums[l]&1)==1) odd--;
                l++;
            }
            if(odd<=goal) ans+=(r-l+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int goal) {
        return sum(nums,goal)-sum(nums,goal-1);
    }
};
