#include<bits/stdc++.h>
using namespace std;
const int V = 66;

char arr[V][V];



string s;
int N;
queue<int> q;

string quard(int y, int x, int size) {
	if (size == 1) return string(1, arr[y][x]);
	char b = arr[y][x];
	string ret = "";
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (b != arr[i][j]) {
				ret += '(';
				ret += quard(y, x, size / 2);
				ret += quard(y, x + size / 2, size / 2);
				ret += quard(y + size / 2, x, size / 2);
				ret += quard(y + size / 2, x + size / 2, size / 2);
				ret += ')';
				return ret;
			}
		}
	}

	return string(1, arr[y][x]);
}


int main() {



	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i+1][j+1] = s[j];
		}
	}
	cout << quard(1, 1, N) << "\n";

	return 0;
}