class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix =1 ;
        int sufix = 1;
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            if(prefix==0) prefix = 1;
            if(sufix==0) sufix = 1;
            prefix*=nums[i];
            sufix*=nums[n-1-i];
            maxi = max(maxi,max(prefix,sufix));
        }
        return maxi;
    }
};
