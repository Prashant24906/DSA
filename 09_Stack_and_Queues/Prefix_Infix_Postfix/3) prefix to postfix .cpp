class Solution {
	public:
	string preToPost(string &pre_exp) {
		std::reverse(pre_exp.begin(), pre_exp.end());
		stack<string> st;
		for (auto it: pre_exp) {
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
		string s = st.top();
		string result = "";
		stack<char> St;
		unordered_map<char, int> operators = {{'+', 1}, {'-', 1}, {'/', 2}, {'*', 2}, {'^', 3}};
		for (auto it: s) {
			if (operators.find(it) != operators.end()) {
				if (St.empty() || St.top() == '(' || operators[it]>operators[St.top()]) {
					St.push(it);
				}
				else {
					while (!St.empty() && St.top() != '(' &&
					((it != '^' && operators[it] <= operators[St.top()]) ||
					(it == '^' && operators[it] < operators[St.top()])))
					{
						result += St.top();
						St.pop();
					}
					St.push(it);
				}
			}
			else if (it == '(' || it == ')') {
				if (it == '(') {
					St.push(it);
				}
				else {
					while (St.top() != '(') {
						result += St.top();
						St.pop();
					}
					St.pop();
				}
			}
			else {
				result += it;
			}
		}
		while (!St.empty() && St.top() != '(') {
			result += St.top();
			St.pop();
		}
		return result;
	}
};
