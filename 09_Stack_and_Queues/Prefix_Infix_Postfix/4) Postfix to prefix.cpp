class Solution {
	public:
	int precedence(char c) {
		if (c == '^')
			return 3;
		else if (c == '*' || c == '/')
			return 2;
		else if (c == '+' || c == '-')
			return 1;
		else
			return - 1;
	}

	// function to check if operator is right-associative
	bool isRightAssociative(char c) {
		return c == '^';
	}
	
	// function to check if a character is an operator
	bool isOperator(char c) {
		return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
	}
	string postToPre(string s) {
		// Postfix to infix
		stack<string> st;
		for (auto it: s) {
			if (it == '+' || it == '-' || it == '*' || it == '/' || it == '%' || it == '^') {
				string temp = "(";
				temp += st.top();
				st.pop();
				temp += it;
				temp += st.top();
				st.pop();
				temp += ')';
				st.push(temp);
			}
			else {
				string temp = "";
				temp += it;
				st.push(temp);
			}
		}
		string temp = st.top();
		reverse(temp.begin(), temp.end());
		int i = 0;
		while (i<temp.size()) {
			if (temp[i] == '(')
				temp[i] = ')';
			else if (temp[i] == ')')
				temp[i] = '(';
			i++;
		}
		s = temp;
		stack<char> sta;
		string result = "";
		
		// scan from right to left
		for (int i = s.length() - 1; i >= 0; i--) {
			char c = s[i];
			
			if (isalnum(c)) {
				result += c;
			}
			else if (c == ')') {
				sta.push(c);
			}
			else if (c == '(') {
				while (!sta.empty() && sta.top() != ')') {
					result += sta.top();
					sta.pop();
				}
				
				// pop ')'
				if (!sta.empty())
					sta.pop();
			}
			else if (isOperator(c)) {
				while (!sta.empty() && isOperator(sta.top()) &&
				(precedence(sta.top()) > precedence(c) ||
				(precedence(sta.top()) == precedence(c) && isRightAssociative(c)))) {
					result += sta.top();
					sta.pop();
				}
				sta.push(c);
			}
		}
		
		// pop remaining operators
		while (!sta.empty()) {
			result += sta.top();
			sta.pop();
		}
		
		// reverse at the end to get correct prefix
		reverse(result.begin(), result.end());
		return result;
		
	}
	
};
