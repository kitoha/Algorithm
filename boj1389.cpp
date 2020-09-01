#include<bits/stdc++.h>

using namespace std;

const int INF = 1e7;
const int MAXN = 101;
int n, m, ans;
int dist[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=n; j++) {
			if (i == j) {
				dist[i][j] = 0;
				continue;
			}
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		dist[a][b] = 1;
		dist[b][a] = 1;

	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
			}
		}
	}


	ans = INF;
	int ac = 0;

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j || dist[i][j] == INF) continue;
			sum += dist[i][j];
		}
		if (ans > sum) {
			ans = sum;
			ac = i;
		}
	}

	cout << ac << "\n";



	return 0;
}