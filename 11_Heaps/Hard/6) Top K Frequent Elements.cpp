class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> count;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        //Build a map O(N)
        for(int i = 0;i<nums.size();i++){
            count[nums[i]]++;
        }

        //Insert into heap of size K and no of unique m O(M log K)
        for (auto it = count.begin(); it != count.end(); ++it) {
            if(pq.size()<k){
                pq.push({it->second,it->first});
            }
            else{
                pair<int,int> temp = pq.top();
                if(it->second>temp.first){
                    pq.pop();
                    pq.push({it->second,it->first});
                }
            }
        }

        //Build the ans array of size K O(K)
        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            cout<<temp.first<<" "<<temp.second<<endl;
            ans.push_back(temp.second);
            pq.pop();
        }
        
        return ans;
    }
};
