class Solution {
	public:
	int totalProvinces = 0;
	void findCircleNum(vector<vector<int>> &adj,vector<int>& visited,int node) {
		int n = adj.size();
		queue<int> q;
		q.push(node);
		visited[node] = 1;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int i = 0; i<adj[node].size(); i++) {
				if (visited[adj[node][i]] == 0) {
					q.push(adj[node][i]);
					visited[adj[node][i]] = 1;
				}
			}
		}
		
	}
	int countConnected(int V, vector<vector<int>> & edges) {
		vector<vector<int>> Connected(V);
		for (int i = 0; i<edges.size(); i++) {
			Connected[edges[i][0]].push_back(edges[i][1]);
			Connected[edges[i][1]].push_back(edges[i][0]);
		}
		vector<int> visited(V, 0);
		for(int i = 0;i<V;i++){
		    if(visited[i]!=1){
		        totalProvinces++;
		        findCircleNum(Connected,visited,i);
		    }
		}
		return totalProvinces;
	}
};
