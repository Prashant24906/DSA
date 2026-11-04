class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> arr = nums;
        int pos = 0;
        int neg = 1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<0){
            arr[neg] = nums[i];
            neg+=2;
            }
            else{
                arr[pos] = nums[i];
                pos+=2;
            }
        }
        return arr;
    }
};
