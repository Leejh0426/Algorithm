#include<bits/stdc++.h>
using namespace std;
const int V = 100;

int visited[V][V];
int height[V][V];
int arr[V][V];


int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };


int N;
int Max;
int result;

void BFS(int y,int x,int k) {
	visited[y][x] = 1;
	queue<pair<int,int>> q;
	int xp, yp;
	q.push({ y, x });
	while (q.size()) {
		for (int i = 0; i < 4; i++) {
			xp = q.front().second + dx[i];
			yp = q.front().first + dy[i];
			if (i == 3) q.pop();
			if (xp < 0 || yp < 0 || xp >= N || yp >= N || height[yp][xp] <= k) continue;
			if (visited[yp][xp]) continue;
			q.push({ yp,xp });
			visited[yp][xp] = 1;
		}
	}

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	result = 0;
	cin >> N;
	Max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> height[i][j];
			if (Max < height[i][j]) Max = height[i][j];
		}
	}

	for (int k = 0; k < 101; k++) {
		int cnt = 0;

		fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (height[i][j] > k && !visited[i][j]) {
					BFS(i, j, k);
					cnt++;
				}
			}
		}
		result = max(result, cnt);
	}

	cout << result << "\n";

	return 0;
}