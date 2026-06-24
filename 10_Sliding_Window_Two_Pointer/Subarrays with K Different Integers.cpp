class Solution {
public:
    int helper(vector<int>& nums, int k) {
        int uniques = 0;
        if(k==0) return 0;
        unordered_map<int,int> mp;
        int l = 0,n = nums.size(),maxi = 0;
        for(int r = 0;r<n;r++){
            if(mp.find(nums[r])==mp.end()) uniques++;
            mp[nums[r]]++;
            while(uniques>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                    uniques--;
                }
                l++;
            }
            maxi+=(r-l+1);
        }
        return maxi;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
};
