#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
bool visit[MAXN];
int n, m, ans;
vector<int> adj[MAXN];

int bfs(int pos) {

	queue<int> q;

	q.push(pos);
	visit[pos] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto next : adj[cur]) {
			if (visit[next]) continue;
			visit[next] = true;
			q.push(next);
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;
		bfs(i);
		ans++;
	}

	cout << ans << "\n";

	return 0;
}