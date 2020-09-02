#include<bits/stdc++.h>

using namespace std;

const int MOD = 10007;
const int MAXN = 1001;
int n;
int dp[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < MAXN; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}

	cin >> n;

	cout << dp[n]%MOD << "\n";


	return 0;
}