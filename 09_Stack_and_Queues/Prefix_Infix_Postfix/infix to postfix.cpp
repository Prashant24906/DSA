class Solution {
  public:
    string infixToPostfix(string& s) {
        string result = "";
        stack<char> st;
        unordered_map<char,int> operators = {{'+', 1},{'-', 1},{'/', 2},{'*', 2},{'^', 3}};
        for(auto it: s){
            if(operators.find(it)!=operators.end()){
                if(st.empty()||st.top()=='('||operators[it]>operators[st.top()]){
                    st.push(it);
                }
                else{
                    while(!st.empty() && st.top()!='(' &&
      ((it != '^' && operators[it] <= operators[st.top()]) ||
       (it == '^' && operators[it] < operators[st.top()])))
{
    result += st.top();
    st.pop();
}
                    st.push(it);
                }
            }
            else if(it=='('||it==')'){
                if(it=='('){
                    st.push(it);
                }
                else{
                    while(st.top()!='('){
                        result+=st.top();
                        st.pop();
                    }
                    st.pop();
                }
            }
            else{
                result+=it;
            }
        }
        while(!st.empty() && st.top()!='('){
            result+=st.top();
            st.pop();
        }
        return result;
    }
};
