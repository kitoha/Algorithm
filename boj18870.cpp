#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
const int MAXN = 1e6 + 1;
int n, cnt;
vector<pi> v;
int ans[MAXN];

bool cmp(pi a, pi b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back({ val,i });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		if (i > 0) {
			if (v[i].first != v[i - 1].first) {
				cnt++;
			}
		}

		ans[v[i].second] = cnt;
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}


	return 0;
}