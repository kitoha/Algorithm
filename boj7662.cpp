#include<bits/stdc++.h>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};
typedef long long ll;
const ll INF = 1e17;
map<int, int> ma;
int test, k;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> test;

	for (int tc = 1; tc <= test; tc++) {
		cin >> k;

		priority_queue<int> maxpq;
		priority_queue<int, vector<int>, cmp> minpq;

		while (k--) {
			char c;
			int val;

			cin >> c >> val;

			if (c == 'I') {
				minpq.push(val);
				maxpq.push(val);
				ma[val]++;

				if (ma[val] == 1) {
					v.push_back(val);
				}
			}
			else {
				ll cur = INF;

				if (val == -1) {

					while (!minpq.empty()) {
						ll tmp = minpq.top();
						minpq.pop();
						if (ma[tmp] > 0) {
							cur = tmp;
							break;
						}
					}

				}
				else {

					while (!maxpq.empty()) {
						ll tmp = maxpq.top();
						maxpq.pop();
						if (ma[tmp] > 0) {
							cur = tmp;
							break;
						}
					}

				}

				if (cur == INF) continue;
				ma[cur]--;
			}
		}

		ll a, b;

		a = b = INF;

		while (!minpq.empty()) {
			int cur = minpq.top();
			minpq.pop();
			if (ma[cur] > 0) {
				a = cur;
				break;
			}
		}


		while (!maxpq.empty()) {
			int cur = maxpq.top();
			maxpq.pop();
			if (ma[cur] > 0) {
				b = cur;
				break;
			}
		}

		if (a == INF || b == INF) cout << "EMPTY\n";
		else cout << b << " " << a << "\n";

		while (!v.empty()) {
			int cur = v.back();
			v.pop_back();

			ma[cur] = 0;
		}

	}


	return 0;
}