// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        std::reverse(pre_exp.begin(), pre_exp.end());
        stack<string> st;
        for(auto it: pre_exp){
            if(it=='+'||it=='-'||it=='*'||it=='/'||it=='%'||it=='^'){
                string temp = "(";
                temp+=st.top();
                st.pop();
                temp+=it;
                temp+=st.top();
                st.pop();
                temp+=')';
                st.push(temp);
            }
            else{
                string temp = "";
                temp+=it;
                st.push(temp);
            }
        }
        return st.top();
    }
};
