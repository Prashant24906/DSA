class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0,r = 0,maxi = 0;
        int zeros = 0;
        while(r<n){
            if(zeros==k&&nums[r]==0){
                while(nums[l] == 1&& l<n)l++;
                l++;
                zeros--;
                continue; 
            }
            if(nums[r]==0){
                zeros++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
