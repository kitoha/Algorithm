#include<bits/stdc++.h>

using namespace std;

const int INF = 1e7;
const int MAXN = 1e6 + 1;
int dp[MAXN];

int solve(int val) {

	if (val == 1) return 0;

	int& ret = dp[val];

	if (ret != -1) return ret;

	ret = INF;

	if (val % 3 == 0) {
		ret = min(ret, solve(val / 3) + 1);
	}

	if (val % 2 == 0) {
		ret = min(ret, solve(val / 2) + 1);
	}

	ret = min(ret, solve(val - 1) + 1);

	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));

	int n;

	cin >> n;


	cout << solve(n) << "\n";
	
	return 0;
}