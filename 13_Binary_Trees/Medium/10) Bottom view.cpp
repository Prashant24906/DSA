class Solution {
	public:
	vector<int> levelOrder(Node* root) {
		if (root == nullptr) {
			return {};
		}
		vector<int> ans;
		map<int, int> mp;
		queue<pair<Node*, int>> q;
		q.push({root,0});
		while (!q.empty()) {
			int line = q.front().second;
			Node* node = q.front().first;
			q.pop();
			mp[line] = node->data;
			if (node->left)
				q.push({node->left,line-1});

			if (node->right)
				q.push({node->right,line+1});

		}
		for(auto it:mp){
		    ans.push_back(it.second);
		}
		return ans;
	}
	vector<int> bottomView(Node *root) {
		return levelOrder(root);
	}
};
