class Solution {
	public:
	string isKSortedArray(int arr[], int n, int k) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		for (int i = 0; i<n; i++) {
			pq.push({arr[i], i});
			if (i >= k) {
				if (abs(pq.top().second - i)>k)
					return "No";
				pq.pop();
			}
		}
		return "Yes";
	}
};
