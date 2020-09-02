#include<bits/stdc++.h>

using namespace std;

const int MAXN = 12;
int test;
int dp[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> test;

	dp[1] = dp[2] = dp[3] = 1;

	for (int i = 2; i < MAXN; i++) {
		for (int j = 1; j <= 3; j++) {
			if (i - j <= 0) continue;
			dp[i] = dp[i] + dp[i - j];
		}
	}

	for (int tc = 1; tc <= test; tc++) {
		int n;

		cin >> n;

		cout << dp[n] << "\n";
	}

	return 0;
}