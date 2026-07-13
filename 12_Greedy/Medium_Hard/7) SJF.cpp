class Solution {
  public:
    int solve(vector<int>& bt) {
        sort(bt.begin(),bt.end());
        int avgTime = 0;
        for(int i = 0;i<bt.size();i++){
            avgTime+=bt[i]*(bt.size() - i - 1);
        }
        return avgTime/bt.size();
    }
};
