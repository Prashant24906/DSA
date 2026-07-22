class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        vector<vector<int>> total;
        for(int i = 0;i<s.size();i++){
            total.push_back({f[i],i,s[i]});     
        }
        sort(total.begin(),total.end());
        vector<int> ans;
        int freeTime = INT_MIN;
        for(auto it:total){
            if(it[2]>freeTime){
                ans.push_back(it[1]+1);
                freeTime = it[0];
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
