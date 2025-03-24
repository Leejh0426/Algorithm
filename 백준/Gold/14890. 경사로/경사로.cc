#include <bits/stdc++.h>
using namespace std;

int n, l;

int arr[101][101];

int visited[101];

int ret;

void turn90() {

	int arr2[101][101];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr2[j][n - 1 - i] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = arr2[i][j];
		}
	}
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout<< arr[i][j]<<' ';
	//	}
	//	cout << "\n";
	//}

	return;
}


void go() {

	for (int i = 0; i < n; i++) {
		int before = 0;
		int cnt = 0;
		bool flag = true;
		for (int j = 0; j < n; j++) {
			if (before == arr[i][j] || j==0) {
				before = arr[i][j];
				cnt++;
			}
			else if (before < arr[i][j]) {
				if ( (cnt >= l) && ((arr[i][j] - before) == 1) ) {
				//	cout <<"before<arr[i][j]:  " << "before : " << before << " cnt : " << cnt << " L : " << l << '\n';
					cnt = 1;
					before = arr[i][j];
				}
				else {
				//	cout << "i: " << i << " j: " << j << '\n';
					flag = false;
					break;
				}
			}
			else if (before > arr[i][j]) {
				int check = j + l;
				cnt = 0;
				while (true) {
					
					if (j >= n || arr[i][j] != before - 1) {
						flag = false; break;
					}
					if (j >= check - 1) {
						before = arr[i][j]; break;
					}
					j++;
				}
				//cout << "j : " << j << " check : " << check <<" before : "<<before<< '\n';
				if (!flag)break;
			}

		
		}
		//cout << "i : " << i << '\n';
		if (flag) {  ret++; }
	}
}


int main() {

	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	go();
	turn90();
	go();

	cout << ret;

	return 0;
}