#include<bits/stdc++.h>

using namespace std;

struct point {
	int y, x, cnt;
	point(int _y, int _x, int _cnt) :y(_y), x(_x), cnt(_cnt) {};
};
const int MAXN = 1001;
int n, m, ans, num;
int visit[MAXN][MAXN],cells[MAXN][MAXN];
vector<point> adj[MAXN];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;

	queue<point> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cells[i][j];

			if (cells[i][j]>0) {
				q.push(point(i,j,1 ));
				visit[i][j] = 1;
			}
			else if(cells[i][j]==0){
				num++;
			}
		}
	}

	if (num == 0) {
		cout << 0 << "\n";
		return 0;
	}

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;

		q.pop();

		for (int i = 0; i <= 3; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visit[ny][nx] || cells[ny][nx]==-1) continue;
		
			visit[ny][nx] = cnt + 1;
			ans = max(ans, visit[ny][nx]);
			num--;

			q.push({ ny,nx,cnt + 1 });
		}
		
	}

	cout << (num ? -1 : ans - 1) << "\n";


	return 0;
}