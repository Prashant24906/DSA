/* Structure of a Binary Search Tree node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int x) {
		data = x;
		left = nullptr;
		right = nullptr;
	}
}; */

class Solution {
	public:
	void findPre(Node* root, int key, Node* &ans) {
		if (!root)
			return ;
		if (root->data >= key)
			findPre(root->left, key, ans);
		else {
			
			ans = root;
			return findPre(root->right, key, ans);
		}
	}
	void findSuc(Node* root, int key, Node* &ans) {
		if (!root)
			return ;
		if (root->data<=key)
			findSuc(root->right, key, ans);
		else {
			ans = root;
			return findSuc(root->left, key, ans);
		}
	}
	vector<Node*> findPreSuc(Node* root, int key) {
		Node* pre = nullptr;
		Node* suc = nullptr;
		findPre(root, key, pre);
		findSuc(root, key, suc);
		return {pre, suc};
	}
};
