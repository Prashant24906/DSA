
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& nums){
        vector<int> ans(nums.size(),0);
        stack<int> st;
        for(int i= nums.size()-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
                st.push(nums[i]);
            }
            else{
                ans[i]=st.top();
                st.push(nums[i]);
            }
        }
        return ans;
    }
};
