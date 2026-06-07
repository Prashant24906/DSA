class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        stack<int> smaller;
        vector<int> ans(arr.size(),0);
        int n = arr.size();
        for(int i = n-1;i>=0;i--){
            while(!smaller.empty()&&arr[i]<=smaller.top()){
                smaller.pop();
            }
            if(smaller.empty()){
                ans[i] = -1;
                smaller.push(arr[i]);
            }
            else{
                ans[i] = smaller.top();
                smaller.push(arr[i]);
            }
        }
        return ans;
    }
};
