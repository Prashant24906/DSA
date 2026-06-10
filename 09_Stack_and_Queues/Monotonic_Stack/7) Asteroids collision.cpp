class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        int i = 0;
        for(int i = 0;i<n;i++){
            while(!st.empty()&&st.top()>0&&st.top()<abs(asteroids[i])&&asteroids[i]<0){
                st.pop();
            }
            if(st.empty()||asteroids[i]>0||st.top()<0){
                st.push(asteroids[i]);
                continue;
            }
            if(abs(asteroids[i])==st.top()){
                st.pop();
                continue;
            }
            
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
