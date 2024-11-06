#include <bits/stdc++.h>

const int max_int = 52;

using namespace std;
typedef long long ll;
int n, m;
char c[max_int][max_int];
ll dp[max_int][max_int];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int visited[max_int][max_int];

ll go(int y, int x) {
	bool flag = true;
	ll& ret = dp[y][x];
	if (ret != -1) return ret;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i] * (c[y][x]-'0');
		int nx = x + dx[i] * (c[y][x] - '0');
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || c[ny][nx] == 'H') continue;
		if (visited[ny][nx]) {
			cout << "-1";
			exit(0);
		}
		visited[ny][nx] = 1;
		ret = max(ret, go(ny, nx)+1);
		/*cout << "ny : " << ny << " nx : " << nx << '\n';
		cout << "ret : " << ret << '\n';*/
		flag = false;
		visited[ny][nx] = 0;
	}
	if (flag) {
		//cout << "y : " << y << " x: " << x << '\n';
		return 1;
	}
	
	return ret;
}

int main() {
	cin >> n>>m;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	
	cout << go(0,0);
	
}
