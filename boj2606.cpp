#include<bits/stdc++.h>

using namespace std;

const int MAXN = 101;
vector<int> adj[MAXN];
int n, m, ans;
bool visit[MAXN];

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

	queue<int> q;

	q.push(1);
	visit[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto next : adj[cur]) {
			if (visit[next]) continue;
			visit[next] = true;
			q.push(next);
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}