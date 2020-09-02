#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
int n, sum, ans;
int arr[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		sum += arr[i];
		ans += sum;
	}

	cout << ans << "\n";


	return 0;
}