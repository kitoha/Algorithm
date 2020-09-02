#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int> pq;

	int n;

	cin >> n;

	while (n--) {
		int val;
		cin >> val;

		if (val) {
			pq.push(val);
		}
		else {
			int cur = 0;

			if (!pq.empty()) {
				cur = pq.top();
				pq.pop();
			}

			cout << cur << "\n";

		}
	}
	return 0;
}