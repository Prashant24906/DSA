class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size() , m = b.size();
        vector<int> ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> visited;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        pq.push({a.back()+b.back(),{n-1,m-1}});
        visited.insert({n-1,m-1});
        while(k--){
            auto sum = pq.top();
            pq.pop();
            int x = sum.second.first;
            int y = sum.second.second;
            ans.push_back(sum.first);
            if(visited.find({x,y-1})==visited.end()){
                int val = a[x] + b[y-1];
                pq.push({val,{x,y-1}});
                visited.insert({x,y-1});
            }
            if(visited.find({x-1,y})==visited.end()){
                int val = a[x-1] + b[y];
                pq.push({val,{x-1,y}});
                visited.insert({x-1,y});
            }
        }
        return ans;
    }
};
