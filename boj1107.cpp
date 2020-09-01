#include<bits/stdc++.h>

using namespace std;

const int INF = 1e7;
const int MAXN = 1e6;
const int MAXM = 10;
int n, m, ans;
bool visit[MAXM];

int chk(int val) {

	if (val == 0) {
		return visit[val] ? 0 : 1;
	}

	int cnt = 0;

	while (val) {
		int tmp = val % 10;
		val /= 10;
		cnt++;
		if (visit[tmp]) return -1;
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		visit[a] = true;
	}

	ans = INF;

	ans = min(ans, abs(100 - n));

	for (int i = 0; i <= MAXN; i++) {

		int tmp = chk(i);

		if (tmp>0) {
			ans = min(ans, abs(i - n) + tmp);
		}
	}

	cout << ans << "\n";


	return 0;
}