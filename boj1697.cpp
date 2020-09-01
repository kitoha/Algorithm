#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
const int INF = 1e7;
const int MAXN = 1e5 * 3;
bool visit[MAXN];
int n, k;
int dir[] = { -1,1,2 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	queue<pi> q;

	q.push({ n,0 });
	visit[n] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;

		q.pop();

		if (cur == k) {
			cout << cnt << "\n";
			return 0;
		}

		for (int i = 0; i < 3; i++) {
			int next = 0;

			if (i == 2) next = cur * dir[i];
			else next = cur + dir[i];

			if (next >=MAXN || next < 0) continue;
			if (visit[next]) continue;
			visit[next] = true;

			q.push({ next,cnt + 1 });
		}

	}

	return 0;
}