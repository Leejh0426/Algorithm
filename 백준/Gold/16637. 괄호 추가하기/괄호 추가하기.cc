#include <bits/stdc++.h>

using namespace std;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int n;

char c[20];
int num[20];

int check1 = 0;
int check2 = 0;

int ret = -999999;

int math(char c, int a, int b) {
	if (c == '+') {
		return a + b;
	}
	else if (c == '*') {
		return a * b;
	}
	else {
		return a - b;
	}
}

void go(int start, int sum) {
	int temp = sum;

	if (start > check2) {
		ret = max(ret, temp);
		return;
	}

	if (start + 2 <= check1) {
		int midTemp = math(c[start + 1], num[start + 1], num[start + 2]);
		go(start + 2, math(c[start], temp, midTemp));
	}
	go(start + 1, math(c[start], temp, num[start + 1]));
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			cin >> num[check1++];
		}
		else {
			cin >> c[check2++];
		}

	}

	go(0, num[0]);

	cout << ret;

	return 0;
}
//for (int i = 0; i <= check2; i++) {
//	if (c[i] == '*') {
//		if (c[i + 1] != '+') {
//			ret *= num[i + 1];
//		}
//		else {
//			ret *= (num[i + 1] + num[i + 2]);
//			i++;
//		}
//	}
//	else if (c[i] == '+') {
//		ret += num[i + 1];
//	}
//	else {
//		if (c[i + 1] != '-') {
//			ret -= num[i + 1];
//		}
//		else {
//			ret -= (num[i + 1] - num[i + 2]);
//			i++;
//		}
//	}
//
//	cout << ret << ' ';
//}