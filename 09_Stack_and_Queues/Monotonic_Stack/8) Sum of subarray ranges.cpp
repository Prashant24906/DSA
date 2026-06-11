class Solution {
public:
    void Next(vector<int>& arr,vector<int>& NextSmaller,vector<int>& NextLarger,vector<int>& PrevSmaller,vector<int>& PrevLarger){
        stack<int> nextlarge;
        stack<int> nextsmall;
        stack<int> prevsmall;
        stack<int> prevlarge;
        for(int i = arr.size()-1;i>=0;i--){
            while(!nextlarge.empty()&&arr[nextlarge.top()]<=arr[i]) nextlarge.pop();
            while(!nextsmall.empty()&&arr[nextsmall.top()]>=arr[i]) nextsmall.pop();
            while(!prevsmall.empty()&&arr[prevsmall.top()]>arr[arr.size()-1-i]) prevsmall.pop();
            while(!prevlarge.empty()&&arr[prevlarge.top()]<arr[arr.size()-1-i]) prevlarge.pop();
            if(!nextlarge.empty())
                NextLarger[i] = nextlarge.top();
            else    
                NextLarger[i] = arr.size();
            nextlarge.push(i);
            if(!nextsmall.empty())
                NextSmaller[i] = nextsmall.top();
            else    
                NextSmaller[i] = arr.size();
            nextsmall.push(i);

            if(!prevsmall.empty())
                PrevSmaller[arr.size()-1-i] = prevsmall.top();
            else    
                PrevSmaller[arr.size()-1-i] = -1;
            prevsmall.push(arr.size()-1-i);
            if(!prevlarge.empty())
                PrevLarger[arr.size()-1-i] = prevlarge.top();
            else    
                PrevLarger[arr.size()-1-i] = -1;
            prevlarge.push(arr.size()-1-i);
        }
    }

    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int MOD = 1e9+7;
        vector<int> NextLarger(nums.size(),0);
        vector<int> PrevLarger(nums.size(),0);
        vector<int> NextSmaller(nums.size(),0);
        vector<int> PrevSmaller(nums.size(),0);
        Next(nums,NextSmaller,NextLarger,PrevSmaller,PrevLarger);
        vector<int> larger(nums.size(),0);
        vector<int> smaller(nums.size(),0);

        for(int i = 0;i<n;i++){
            smaller[i] = (NextSmaller[i]-i)*(i-PrevSmaller[i]);
            larger[i] = (NextLarger[i]-i)*(i-PrevLarger[i]);
        }
        for(int i = 0;i<n;i++){
            ans+=((long long)nums[i]*(long long)larger[i])-((long long)smaller[i]*(long long)nums[i]);
        }
        return ans;
    }
};
