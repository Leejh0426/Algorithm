#include <bits/stdc++.h>
using namespace std;

int n;

bool arr[4000004];
int ret;
priority_queue<int> pq;

int main() {

	cin >> n;

	for (int i = 2; i*i <= n; i++) {
		if (!arr[i]) {
			for (int j = i * i; j <= n; j += i) // 이전코드랑비교해서 여기만수정
			{
				arr[j] = true;
			}
		 }
	}

	int sum = 0;
	
	
	for (int i = n; i > 1; i--) {
		if (!arr[i]) {
			sum += i;
			pq.push(i);
			if (sum == n) {
				ret++;
				sum -= pq.top();
				pq.pop();
			//	cout << "I : " << i << '\n';
			}
			else if (sum > n) {
				sum -= pq.top();
				pq.pop();
			}
		}
		//cout<<i<<" "<< sum << '\n';
	}

	cout << ret;

	return 0;
}