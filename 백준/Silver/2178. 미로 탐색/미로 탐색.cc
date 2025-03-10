#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int n, m;

string s[101];
int visited[101][101];

void bfs(int y, int x) {
	queue<pair<int,int>> q;
	q.push({y,x});
	while (!q.empty()) {
		pair<int,int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (s[ny][nx] == '0') continue;
			if (visited[ny][nx] != 0) continue;
			visited[ny][nx] = visited[p.first][p.second] + 1;
			q.push({ ny,nx });
		}
	}

	
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	visited[0][0] = 0;
	bfs(0, 0);
	
	cout << visited[n-1][m-1]+1;
	
	return 0;
}
