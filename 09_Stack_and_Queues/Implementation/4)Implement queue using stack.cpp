class MyQueue {

  public:
    stack <int> st;
    MyQueue() {
        // Initialize your data members
    }

    void push(int x) {
        st.push(x);
    }

    int pop() {
        if(st.size()==0) return -1;
        if(st.size()==1){
            int temp = st.top();
            st.pop();
            return temp;
        }
        int temp = st.top();
        st.pop();
        int ans = pop();
        st.push(temp);
        return ans;
    }

    int peek() {
        if(st.size()==0) return -1;
        if(st.size()==1){
            return st.top();
        }
        int temp = st.top();
        st.pop();
        int ans = peek();
        st.push(temp);
        return ans;
    }
    bool empty() {
        return st.size()<=0?true:false;
    }
};
