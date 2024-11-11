#include <bits/stdc++.h>

const int max_int = 100001;
using namespace std;

int n,k;
int a[max_int];
int ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < k; i++) {
		sum += a[i];
	}

	int front = 0;
	int end = k;

	ret = sum;

	while (true) {
		if (end >= n) break;
		sum = sum - a[front++] + a[end++];
		ret = max(ret, sum);

	}
	
	cout << ret;

	return 0;
}


