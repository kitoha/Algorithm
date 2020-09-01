#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
vector<pi> v;
int n;

bool cmp(pi a, pi b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;

		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), cmp);

	int idx = 0;
	int ans = 1;

	for (int i = 1; i < v.size(); i++) {
		pi cur = v[idx];
		pi next = v[i];

		if (cur.second > next.first) continue;

		idx = i;
		ans++;
	}

	cout << ans << "\n";

	return 0;
}