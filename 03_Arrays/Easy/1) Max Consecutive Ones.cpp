class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max = INT_MIN;
        int i = 0;
        int n = nums.size();
        while(i<n){
            if(nums[i]==1) count++;
            else count = 0;
            if(max<count) max = count;
            i++;
        }   
        return max;
    }
};
