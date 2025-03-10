#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int visited[100][100];
int arr[100][100];

int N, M;

void BFS() {
	visited[0][0] = 1;
	queue<pair<int,int>> q;
	q.push({ 0,0 });
	while (q.size()) {
		pair<int, int> p = q.front();
		q.pop();
		int y = p.first;
		int x = p.second;
		int yd;
		int xd;
		for (int i = 0; i < 4; i++) {
			yd = y + dy[i];
			xd = x + dx[i];
			if (xd < 0 || yd < 0 || yd >= N || xd >= M || arr[yd][xd] == 0) continue;
			if (visited[yd][xd] != 0) continue;
			visited[yd][xd] = visited[y][x] + 1;
			q.push({ yd,xd });
		}

	}

}

int main() {
	cin >> N >> M;
	string Miro;

	for (int i = 0; i < N; i++) {
		cin >> Miro;
		for (int j = 0; j < M; j++) {
			arr[i][j]= Miro[j] - '0';
		}
	}

	BFS();
	cout << visited[N-1][M-1];
}
