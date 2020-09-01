#include<bits/stdc++.h>

using namespace std;

map<string, string> a;

int n, m;

string intToString(int pos) {
	
	string ret = "";

	while (pos > 0) {
		int tmp = pos % 10;
		pos /= 10;

		ret.push_back((char)(tmp+'0'));
	}

	reverse(ret.begin(), ret.end());

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <=n; i++) {
		string s, t;
		cin >> s;

		t = intToString(i);

		a[s] = t;
		a[t] = s;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		cout << a[s] << "\n";
	}

	return 0;
}