
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        vector<int> ans;
        for(int i = 0;i<indices.size();i++){
            int cnt = 0;
            for(int j = indices[i];j<arr.size();j++){
                if(arr[j]>arr[indices[i]]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
