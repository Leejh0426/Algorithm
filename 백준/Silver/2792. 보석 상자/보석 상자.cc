#include<bits/stdc++.h>

using namespace std;

int n;
int m;

int a[300000];

int ret=987654321;

bool search(int mid) {
	int t_ret = 0;
	for (int j = 0; j < m; j++) {
		t_ret += a[j] / mid;
		if (a[j] % mid) t_ret++;
	}
	
	return t_ret <= n;

}


int main() {

	cin >> n >> m;
	int left = 1, right = -1, mid;

	for (int i = 0; i < m; i++) {
		cin >> a[i];
		right = max(right, a[i]);
	}

	

	while (left <= right) {
		mid = (left + right) / 2;
		if (search(mid)) {
			ret = min(ret, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ret;

	
	return 0;
}
