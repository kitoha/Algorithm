#include<bits/stdc++.h>

using namespace std;

const int MAXN = 21;
int m;
int visit[MAXN];
string number[] = { "add","remove","check","toggle","all","empty" };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m;

	while (m--) {
		string s;
		int val;
		cin >> s ;

		if (s == number[0]) {
			cin >> val;
			visit[val] = 1;
		}
		else if(s==number[1]){
			cin >> val;
			visit[val] = 0;
		}
		else if (s == number[2]) {
			cin >> val;
			cout << visit[val] <<"\n";
		}
		else if (s == number[3]) {
			cin >> val;
			visit[val] = !visit[val];
		}
		else if (s == number[4]) {
			for (int i = 0; i < MAXN; i++) {
				visit[i] = 1;
			}
		}
		else if (s == number[5]) {
			for (int i = 0; i < MAXN; i++) {
				visit[i] = 0;
			}
		}

	}

	return 0;
}