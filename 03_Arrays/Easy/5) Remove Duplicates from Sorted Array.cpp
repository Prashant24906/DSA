class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int temp = nums[0];
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=temp){
                ans.push_back(nums[i]);
                temp = nums[i];
            }
        }
        return ans;
    }
};
