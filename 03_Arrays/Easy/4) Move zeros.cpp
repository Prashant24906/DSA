class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int temp = -1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0){
                temp = i;
                break;
            }
        }
        if(temp == -1) return ;
        for(int i = temp+1;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[temp]);
                temp++;
            }
        }
    }
};
