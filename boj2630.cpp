#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
const int MAXN = 129;
int cells[MAXN][MAXN];
int n;

pi operator+(pi a, pi b) {
	pi ret;
	ret.first = a.first + b.first;
	ret.second = a.second + b.second;

	return ret;
}

pi solve(int y, int x, int ny, int nx) {

	int a, b;
	a = b = 0;

	for (int i = y; i <=ny; i++) {
		for (int j = x; j <= nx; j++) {
			if (cells[i][j]) a++;
			else b++;
		}
	}

	if (a == 0) return { 1,0 };
	else if (b == 0) return { 0,1 };

	pi ret = { 0,0 };

	ret =ret + solve(y, x, (y + ny) / 2, (x + nx) / 2);
	ret = ret + solve(y, (x + nx) / 2 + 1, (y + ny) / 2, nx);
	ret = ret + solve((y + ny) / 2 + 1, x, ny, (x + nx) / 2);
	ret = ret + solve((y + ny) / 2 + 1, (x + nx) / 2 + 1, ny, nx);

	return ret;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cells[i][j];
		}
	}

	pi ans = solve(0, 0, n - 1, n - 1);

	cout << ans.first << "\n" << ans.second << "\n";

	return 0;
}