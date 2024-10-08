#include<bits/stdc++.h>

using namespace std;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };


const int max_int = 54;

int r, c, t;
int a[max_int][max_int];
int temp[max_int][max_int];

int aircy1;
int aircy2;

void airclean(int y,int x) {
	while (y>0) {
		a[y][x] = a[y - 1][x];
		y--;
	}
	while (x!=c-1) {
		a[y][x] = a[y][x + 1];
		x++;
	}
	while (y != aircy1) {
		a[y][x] = a[y + 1][x];
		y++;
	}
	while (x != 0) {
		a[y][x] = a[y][x - 1];
		x--;
	}
	a[aircy1][1] = 0;
}

void airclean2(int y, int x) {
	while (y != r) {
		a[y][x] = a[y + 1][x];
		y++;
	}
	y--;
	while (x != c - 1) {
		a[y][x] = a[y][x + 1];
		x++;
	}
	while (y!=aircy2) {
		a[y][x] = a[y - 1][x];
		y--;
	}
	while (x != 0) {
		a[y][x] = a[y][x - 1];
		x--;
	}
	a[aircy2][1] = 0;
}

int main() {
	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) {
				aircy2 = i;
			}
		}
	}
	aircy1 = aircy2 - 1;

	while (t--) {
		//미세먼지확산
		fill(&temp[0][0], &temp[0][0] + max_int * max_int, 0);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (a[i][j] < 5) continue;
				int dust = a[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
					if (a[ny][nx] == -1) continue;
					temp[ny][nx] += dust;
					a[i][j] -= dust;
				}
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				a[i][j] += temp[i][j];
			}
		}
		// 미세먼지 확산
	/*	cout << "\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}*/

		//공기청정기작동
		airclean(aircy1-1,0);
		airclean2(aircy2+1,0);
		//공기청정기

	/*	cout << "\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}*/

	}

	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if(a[i][j] != -1) sum += a[i][j];
		}
	}

	cout << sum;


	return 0;

}







