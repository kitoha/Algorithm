#include<bits/stdc++.h>

using namespace std;

map<string, int> ma;
vector<string> v, ans;
int n, m;

int solve(int cnt) {
	for (int i = 0; i < cnt; i++) {
		string s;
		cin >> s;

		if (ma[s] == 0) {
			v.push_back(s);
		}
		ma[s]++;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	solve(n);
	solve(m);

	for (auto next : v) {
		if (ma[next] >= 2) {
			ans.push_back(next);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";

	for (auto next : ans) {
		cout << next << "\n";
	}

	return 0;

}