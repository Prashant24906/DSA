class Solution {
public:
    vector<int> NextSmall(vector<int>& arr,vector<int>& NextSmaller){
        stack<int> st;
        for(int i = arr.size()-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty())
                NextSmaller[i] = st.top();
            else    
                NextSmaller[i] = arr.size();
            st.push(i);
        }
        return NextSmaller;
    }
    vector<int> PrevSmall(vector<int>& arr,vector<int>& PrevSmaller){
        stack<int> st;
        for(int i = 0;i<arr.size();i++){
            while(!st.empty()&&arr[st.top()]>arr[i]) st.pop();
            if(!st.empty())
                PrevSmaller[i] = st.top();
            else  
                PrevSmaller[i] = -1;
            st.push(i);
        }
        return PrevSmaller;
    }
    int sumSubarrayMins(vector<int>& arr) {
        long long res = 0;
        int MOD = 1e9 + 7;
        int n = arr.size();
        stack<int> st;
        vector<int> NextSmaller(arr.size(),0);
        vector<int> PrevSmaller(arr.size(),0);
        NextSmall(arr,NextSmaller);
        PrevSmall(arr,PrevSmaller);
        for(int i = 0;i<arr.size();i++){
            long long prod = ((i-PrevSmaller[i])*(NextSmaller[i]-i))%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        }   
        return res;
    }
};
