#include<bits/stdc++.h>

using namespace std;

const int max_int = 101;

int n;
int k;
int a[max_int][max_int];

int L;

int directChange;

int tx, ty;

int t;
int count_l;

int ny = 0;
int nx = 0;
vector<pair<int, char>> v;

int direct;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int tail_y;
int tail_x;

queue<pair<int,int>> tail;

void spin(char c) {
	if (c == 'D') {
		direct = (direct+1)%4;
	}
	else {
		if(direct>0) direct -=1;
		else { direct = 3; }
	}
	
}

int main() {

	cin >> n;
	cin >> k;

	while (k--) {
		cin >> ty >> tx;
		a[ty-1][tx-1] = true;
	}

	cin >> L;
	int temp_n;
	char c;
	for (int i = 0; i < L; i++) {
		cin >> temp_n >> c;
		v.push_back({ temp_n,c });
	}
	a[ny][nx] = 2;
	tail.push({ 0,0 });
	while (true) {


		/*cout << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "t: " << t << "\n";
		cout << "ny : " << ny << "  nx : " << nx << "\n";*/

		ny += dy[direct];
		nx += dx[direct];
		t += 1;
		/*cout << "1초 이후 ---  ny : " << ny << "  nx : " << nx << "\n";*/
		if (nx < 0 || ny < 0 || nx >= n || ny >= n || a[ny][nx] == 2) break;

		
		if (a[ny][nx] == 0) {
			a[tail.front().first][tail.front().second] = 0;
			tail.pop();
		}
		tail.push({ ny,nx });
		a[ny][nx] = 2;
	

		//t += 1;

		if (count_l<L && v[count_l].first == t) {
			if (v[count_l].second == 'D') {
				spin('D');
			}
			else {
				spin('L');
			}
			count_l++;
		}
		
	}

	cout << t;

	return 0;
}
