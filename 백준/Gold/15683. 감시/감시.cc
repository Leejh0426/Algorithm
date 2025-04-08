#include<bits/stdc++.h>


using namespace std;

int n, m;

int arr[20][20];
int testarr[20][20];
vector<pair<int, int>> v;

int checkdirect[20];

int ret = 987654321;

void clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			testarr[i][j] = arr[i][j];
		}
	}
	return;
}

void fill(int y, int x,int direct) {
	int dy = y;
	int dx = x;
	if (direct == 1) {
		while (true) {
			dx++;
			if (dx < 0 || dx >= m || testarr[dy][dx] == 6) break;
			if (testarr[dy][dx] != 0) continue;
			testarr[dy][dx] = -1;
		}
	}
	else if (direct == 2) {
		while (true) {
			dy++;
			if (dy < 0 || dy >= n || testarr[dy][dx] == 6) break;
			if (testarr[dy][dx] != 0) continue;
			testarr[dy][dx] = -1;
		}
	}
	else if (direct == 3) {
		while (true) {
			dx--;
			if (dx < 0 || dx >= m || testarr[dy][dx] == 6) break;
			if (testarr[dy][dx] != 0) continue;
			testarr[dy][dx] = -1;
		}
	}
	else if (direct == 4) {
		while (true) {
			dy--;
			if (dy < 0 || dy >= n || testarr[dy][dx] == 6) break;
			if (testarr[dy][dx] != 0) continue;
			testarr[dy][dx] = -1;
		}
	}

	return;
}


void check() {
	for (int i = 0; i < v.size(); i++) {
		int dy = v[i].first;
		int dx = v[i].second;
		if (testarr[dy][dx] == 1) {
			if (checkdirect[i] == 1) fill(dy, dx, 1);
			else if (checkdirect[i] == 2) fill(dy, dx, 2);
			else if (checkdirect[i] == 3) fill(dy, dx, 3);
			else if (checkdirect[i] == 4) fill(dy, dx, 4);
		}
		else if (testarr[dy][dx] == 2) {
			if (checkdirect[i] == 1) { fill(dy, dx, 1); fill(dy, dx, 3); }
			else if (checkdirect[i] == 2) { fill(dy, dx, 2); fill(dy, dx, 4);}
		}
		else if (testarr[dy][dx] == 3) {
			if (checkdirect[i] == 1) { fill(dy, dx, 1); fill(dy, dx, 4); }
			else if (checkdirect[i] == 2) { fill(dy, dx, 1); fill(dy, dx, 2); }
			else if (checkdirect[i] == 3) { fill(dy, dx, 2); fill(dy, dx, 3); }
			else if (checkdirect[i] == 4) { fill(dy, dx, 3); fill(dy, dx, 4); }
		}
		else if (testarr[dy][dx] == 4) {
			if (checkdirect[i] == 1) { fill(dy, dx, 1); fill(dy, dx, 4); fill(dy, dx, 3);}
			else if (checkdirect[i] == 2) { fill(dy, dx, 1); fill(dy, dx, 4); fill(dy, dx, 2); }
			else if (checkdirect[i] == 3) { fill(dy, dx, 1); fill(dy, dx, 2); fill(dy, dx, 3); }
			else if (checkdirect[i] == 4) { fill(dy, dx, 2); fill(dy, dx, 4); fill(dy, dx, 3); }
		}
		else if (testarr[dy][dx] == 5) {
			fill(dy, dx, 1); 
			fill(dy, dx, 2); 
			fill(dy, dx, 3);
			fill(dy, dx, 4);
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (testarr[i][j] == 0) sum++;
		}
	}
	//cout << "=======\n";

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << testarr[i][j];
	//	}
	//	cout << '\n';
	//}

	//cout << "=======\n";


	ret = min(ret, sum);
	return;
}


void go(int start) {

	if (start > v.size() - 1) {
		check();
		clear();
		return;
	}
	
	int dy = v[start].first;
	int dx = v[start].second;

	if(arr[dy][dx]==2){
		checkdirect[start] = 1;
		go(start + 1);
		checkdirect[start] = 2;
		go(start + 1);
	}
	else if (arr[dy][dx] == 5) {
		go(start + 1);
	}
	else {
		checkdirect[start] = 1;
		go(start + 1);
		checkdirect[start] = 2;
		go(start + 1);
		checkdirect[start] = 3;
		go(start + 1);
		checkdirect[start] = 4;
		go(start + 1);
	}
	
	return;
	
}

int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			testarr[i][j] = arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				v.push_back({ i, j });
			}
		}
	}

	if (v.size() == 0) { check(); }
	else { go(0); }

	cout << ret;

	return 0;
}