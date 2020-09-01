#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 17;
int n, r, c, ans;
bool flag;

int dfs(int y, int x, int ny, int nx) {
	if (flag) return 0;

	if (y > r || ny<r || x>c || nx < c) {
		ans += (ny - y + 1) * (nx - x + 1);
		return 0;
	}
	if (y == ny && x == nx) {
		if (!flag) {
			if (r == y && c == x) {
				flag = true;
			}
			ans++;
		}
		return 0;
	}

	dfs(y, x, (y+ny) / 2, (x+nx) / 2);
	dfs(y, (x+nx) / 2 + 1, (y+ny) / 2, nx);
	dfs((y+ny) / 2 + 1, x, ny, (x+nx) / 2);
	dfs((y+ny) / 2 + 1, (x+nx) / 2 + 1, ny, nx);

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> r >> c;

	ll m = pow(2, n) - 1;

	dfs(0, 0, m, m);

	cout << ans - 1 << "\n";


	return 0;
}