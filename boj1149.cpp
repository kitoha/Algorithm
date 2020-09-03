#include<bits/stdc++.h>

using namespace std;

const int INF = 1e7;
const int MAXN = 4;
const int MAXM = 1001;
int dp[MAXN][MAXM], cost[MAXM][MAXN];
int n;

int solve(int val,int pos) {
	if (pos >=n) return 0;

	int& ret = dp[val][pos];

	if (ret != -1) return ret;

	ret = INF;

	for (int i = 1; i <MAXN; i++) {
		if (val == i) continue;
		ret = min(ret, solve(i, pos + 1) + cost[pos][i]);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i <n; i++) {
		for (int j = 1; j <MAXN; j++) {
			cin >> cost[i][j];
		}
	}

	cout << solve(0, 0) << "\n";

	return 0;
}