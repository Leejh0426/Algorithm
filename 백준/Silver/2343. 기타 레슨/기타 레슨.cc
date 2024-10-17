#include<bits/stdc++.h>

using namespace std;

int n, m;
int mx;
int a[100001];

int ret = 987654321;

bool check(int mid) {
	if (mx > mid) return false;
	int temp = mid;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (mid - a[i] < 0) {
			mid = temp;
			cnt++;
		}
		mid -= a[i];
	}
	if (mid != temp)cnt++;
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

	int left = 1, right = sum ,mid;

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
