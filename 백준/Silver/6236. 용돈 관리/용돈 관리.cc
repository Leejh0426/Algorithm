#include<bits/stdc++.h>

using namespace std;

int n, m;
int mx;
int a[100001];

int ret = 1987654321;

bool check(int mid) {

	int t_sum=0;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (t_sum + a[i] > mid) {
			t_sum = 0;
			cnt++;
		}
		t_sum += a[i];
	}
	return cnt <= m;
	
}

int main() {

	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}

	int left = mx, right = sum ,mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (check(mid)) {
			ret = min(mid,ret);
			right = mid - 1;
			
		}
		else {
			left = mid + 1;
		}
	}

	cout << ret;
	

	return 0;
}
