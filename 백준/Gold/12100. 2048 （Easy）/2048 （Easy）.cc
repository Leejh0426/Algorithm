#include<bits/stdc++.h>
using namespace std;

const int max_int = 21;
int n;

int arr[max_int][max_int];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int ret = 2;

void go(int a[max_int][max_int], int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ret = max(ret, a[i][j]);
			}
		}
		return;
	}
	int temp_a[max_int][max_int];
	for (int k = 0; k < 4; k++) {
		fill(&temp_a[0][0], &temp_a[0][0] + max_int * max_int, 0);
		for (int i = 0; i < n; i++) {

			if (k == 0) {  // 아래, i가 x역할
				int ny = n - 1;
				for (int j = n - 1; j >= 0; j--) {
					if (!temp_a[ny][i]) temp_a[ny][i] += a[j][i];
					else if (temp_a[ny][i] == a[j][i]) temp_a[ny--][i] += a[j][i];
					else if (a[j][i] != 0) temp_a[--ny][i] = a[j][i];
				}
			}

			else if (k == 1) { // 좌 , i가 y역할
				int nx = 0;
				for (int j = 0; j < n; j++) {
					if (!temp_a[i][nx]) temp_a[i][nx] += a[i][j]; 
					else if(temp_a[i][nx] == a[i][j]) temp_a[i][nx++] += a[i][j];
					else if (a[i][j] != 0)temp_a[i][++nx] = a[i][j];
				}
			
			}
			else if (k == 2) {// 위 i가 x역할
				int ny = 0;
				for (int j = 0; j < n; j++) {
					if (!temp_a[ny][i]) temp_a[ny][i] += a[j][i]; 
					else if (temp_a[ny][i] == a[j][i]) { temp_a[ny][i] += a[j][i];
					ny += 1;
					}
					else if(a[j][i] !=0) temp_a[++ny][i] = a[j][i];
				}
			
			}
			else if(k==3){  //우, i가 y역할
				int nx = n - 1;
				for (int j = n - 1; j >= 0; j--) {
					if (!temp_a[i][nx] ) temp_a[i][nx] += a[i][j];
					else if (temp_a[i][nx] == a[i][j]) temp_a[i][nx--] += a[i][j];
					else if (a[i][j] != 0) temp_a[i][--nx] = a[i][j];
				}
				
			}

		}
		////----
		//cout << "k : "<<k<<"-----\n";

		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		cout << temp_a[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//if (ret == 512) exit(0);
		//cout << "\n";
		//cout << "\n";
		////-----
		//cout << "원본---\n";
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		cout << a[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";


		////----

		go(temp_a, cnt + 1);
		
	}
		
	

}


int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 0;

	go(arr, cnt);

	cout << ret;

	return 0;
}