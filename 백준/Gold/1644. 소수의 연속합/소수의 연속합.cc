#include <bits/stdc++.h>
using namespace std;

int n;

bool arr[4000004];
int ret;
priority_queue<int> pq;

int p,lo,hi;
int a[4000004];

int main() {

	cin >> n;

	for (int i = 2; i*i <= n; i++) {
		if (!arr[i]) {
			for (int j = i * i; j <= n; j += i)
			{
				arr[j] = true;
			}
		 }
	}

	int sum = 0;
	
	for (int i = 2; i <= n; i++) {
		if (!arr[i]) a[p++] = i;
	}


	while (1) {
		if (sum >= n) sum -= a[lo++];
		else if (hi == p) break;
		else sum += a[hi++];
		if (sum == n) ret++;
	}

	cout << ret;
	return 0;
}