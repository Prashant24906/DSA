class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el;
        for(int i = 0;i<nums.size();i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(el == nums[i]){
                cnt++;
            }
            else cnt--;
        }
        int c1 = 0;
        for(int i = 0;i<nums.size();i++){
            if(el == nums[i]) c1++;
        }
        if(c1>nums.size()/2) return el; 
        return -1;
    }
};
