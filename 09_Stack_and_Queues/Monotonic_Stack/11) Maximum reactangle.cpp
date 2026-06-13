class Solution {
public:
void NextSmall(vector<int>& heights,vector<int> &NextSmaller,vector<int> &PrevSmaller){
        stack<int> st;
        stack<int> prevsmall;
        int n = heights.size();
        for(int i = n-1;i>=0;i--){
            while(!prevsmall.empty()&&heights[prevsmall.top()]>heights[heights.size()-1-i]) prevsmall.pop();
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!prevsmall.empty())
                PrevSmaller[heights.size()-1-i] = prevsmall.top();
            else    
                PrevSmaller[heights.size()-1-i] = -1;
            prevsmall.push(heights.size()-1-i);

            if(st.empty()){
                NextSmaller[i] = n;
                st.push(i);
            }
            else{
                NextSmaller[i] = st.top();
                st.push(i);
            }
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> NextSmaller(heights.size(),0);
        vector<int> PrevSmaller(heights.size(),0);
        NextSmall(heights,NextSmaller,PrevSmaller);
        int n = heights.size();
        int maxi = 0;
        for(int i = 0;i<n;i++){
            int area = NextSmaller[i]- PrevSmaller[i]-1;
            maxi = max(maxi,heights[i]*area);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> ones(matrix.size(), vector<int>(matrix[0].size(), 0));
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0;i<m;i++){
            int count = 0;
            for(int j = 0;j<n;j++){
                if(matrix[j][i]=='1'){
                    count++;
                }
                else count = 0;
                ones[j][i] = count;
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            int reactangle = largestRectangleArea(ones[i]);
            ans = max(ans,reactangle);
        }
        return ans;
    }
};
