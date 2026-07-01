class Solution {
  public:
    void replaceWithRank(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        for(int i = 0;i<arr.size();i++){
            arr[pq.top().second] = i;
            pq.pop();
        }
    }
};
