class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int maxsum = INT_MIN;
        int sum = 0;
        for(int i = 0;i<arr.size();i++){
            sum+=arr[i];
            maxsum = max(sum,maxsum);
            if(sum<=0){
                sum = 0;
            }
        }
        return maxsum;
        
    }
};
