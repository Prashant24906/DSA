class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.size()) return "0";
        string ans = "";
        stack<char>st;
        int count = 0;
        for(int i = 0;i<num.size();i++){
            while(!st.empty()&&st.top()>num[i]&&k>count){
                st.pop();
                count++;
            }
            st.push(num[i]);
        }
        while(!st.empty()&&k!=count){
            st.pop();
            count++;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        while(i<ans.size()&&ans[i]=='0') i++;
        ans = ans.substr(i,ans.size()-i);    
        if(ans.size()==0) return "0";    
        if(ans.size()==num.size()) return num.substr(0,num.size()-k);
        return ans;
    }
};
