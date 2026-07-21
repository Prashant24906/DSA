class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        priority_queue<pair<int,int>> HighestProfit;
        int maxi = INT_MIN;
        int totalProfit = 0,totalJob = 0;
        for(int i = 0;i<profit.size();i++){
            HighestProfit.push({profit[i],deadline[i]});
            maxi = max(maxi,deadline[i]);
        }
        vector<int> slots(maxi+1,0);
        while(!HighestProfit.empty()){
            pair<int,int> temp = HighestProfit.top();
            for(int j = temp.second-1;j>=0;j--){
            if(slots[j]==0){
                slots[j] = 1;
                totalProfit+=temp.first;
                totalJob++;
                break;
            }
            }
            HighestProfit.pop();
        }
        return {totalJob,totalProfit};
    }
};
