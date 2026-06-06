class Solution {
  public:
  int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

// function to check if operator is right-associative
bool isRightAssociative(char c) {
    return c == '^';
}

// function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// function to convert infix expression to prefix
string infixToPrefix(string s) {
    stack<char> st;
    string result = "";

    // scan from right to left
    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];

        if (isalnum(c)) {
            result += c;
        }
        else if (c == ')') {
            st.push(c);
        }
        else if (c == '(') {
            while (!st.empty() && st.top() != ')') {
                result += st.top();
                st.pop();
            }
            
            // pop ')'
            if (!st.empty()) st.pop(); 
        }
        else if (isOperator(c)) {
            while (!st.empty() && isOperator(st.top()) &&
                   (precedence(st.top()) > precedence(c) ||
                   (precedence(st.top()) == precedence(c) && isRightAssociative(c)))) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // pop remaining operators
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // reverse at the end to get correct prefix
    reverse(result.begin(), result.end());
    return result;
}

};
