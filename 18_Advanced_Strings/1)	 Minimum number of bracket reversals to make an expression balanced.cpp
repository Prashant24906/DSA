class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int cnt = 0;
        for(auto it:s){
            if(it=='('){
                st.push(1);
            }
            else if(it==')'){
                if(st.empty()){
                    cnt++;
                }
                else st.pop();
            }
        }
        while(!st.empty()){
            cnt++;
            st.pop();
        }
        return cnt;
    }
};
