#include<bits/stdc++.h>
using namespace std;
#define ff first
#define SZ 200005

vector<int> adj[SZ];
pair<int, int> bfs(int src, vector<int>&dp)
{
	int d = 0;
	queue<pair<int, int> > q;
	q.push({src, 0});
	vector<bool> vis(SZ, false);
	pair<int, int>  u;

	while (!q.empty()) {
		u = q.front();
		vis[u.first] = true;
		q.pop();
		dp[u.first] = u.second;
		for (int v : adj[u.first])
			if (!vis[v])
				q.push({v, u.second + 1});
	}
	return u;
}

pair<int, int> dfs(int node, vector<int>& dp, int par = -1, int dist = 0) {

	pair<int, int> res = {dist, node};
	dp[node] = dist;
	for (auto x : adj[node]) {
		if (x == par) continue;
		res = max(res, dfs(x, dp, node, dist + 1));
	}

	return res;
}

int main() {

	int n;
	cin >> n;
	int x, y;

	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<int>dp1(SZ), dp2(SZ), dp3(SZ);
	pair<int, int>  end1 = dfs(0, dp3);
	pair<int, int>  end2 = dfs(end1.second, dp2);
	pair<int, int> end3 =  dfs(end2.second, dp1);

	int len = end2.first;

	for (int i = 0; i < n; i++) {
		cout << max(dp1[i], dp2[i]) << " ";
	}
	cout << endl;


}