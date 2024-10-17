#include<bits/stdc++.h>

using namespace std;

int n, m;
long long mx;
long long a[100001];

long long ret = 100000 * 10000;

bool check(int mid) {
	if (mx > mid) return false;
	long long sum = 0;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (sum + a[i] > mid) {
			sum = a[i];
			cnt++;
			if (cnt > m) return false;
		}
		else sum += a[i];
		
	}

	return true;
}

int main() {

	cin >> n >> m;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}

	long long left = 1, right = sum ,mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (check(mid)) {
			ret = mid;
			right = mid - 1;
			
		}
		else {
			left = mid + 1;
		}
	}

	cout << ret;
	

	return 0;
}
