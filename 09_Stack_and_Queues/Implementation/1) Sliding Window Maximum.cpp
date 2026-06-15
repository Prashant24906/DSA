class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> de;
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            while(!de.empty()&&de.front()<=i-k) de.pop_front();
            while(!de.empty()&&nums[i]>nums[de.back()]) de.pop_back();
            de.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[de.front()]);
            }
        }
        return ans;

    }
};
