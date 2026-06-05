// User function Template for C++

class Solution {
  public:
    string postToInfix(string &pre_exp) {
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
        string temp = st.top();
        reverse(temp.begin(),temp.end());
        int i = 0;
        while(i<temp.size()){
            if(temp[i]=='(')
                temp[i] = ')';
            else if(temp[i]==')')
                temp[i] = '(';
            i++;
        }
        return temp;
    }
};
