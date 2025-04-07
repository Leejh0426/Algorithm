#include<bits/stdc++.h>

using namespace std;


int n;
int arr[14];

int math[4];

int ret_max=INT_MIN;
int ret_min=INT_MAX;


void go(int start, int sum) {
	if (start > n - 1) {
		ret_max = max(ret_max, sum);
		ret_min = min(ret_min, sum);
		return;
	}

	if (math[0]) {
		sum += arr[start];
		math[0]--;
		go(start+1, sum);
		sum -= arr[start];
		math[0]++;
	}
	if (math[1]) {
		math[1]--;
		sum -= arr[start];
		go(start + 1, sum);
		sum += arr[start];
		math[1]++;
	}
	if (math[2]) {
		math[2]--;
		sum *= arr[start];
		go(start + 1, sum);
		sum /= arr[start];
		math[2]++;
	}
	if (math[3]) {
		math[3]--;
		int temp=0;
		if (sum % arr[start]) temp = sum%arr[start];
		sum /= arr[start];
		go(start + 1, sum);
		sum *= arr[start];
		sum += temp;
		math[3]++;
	}

	return;
}



int main() {



	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> math[i];
	}

	go(1, arr[0]);

	cout << ret_max << '\n' << ret_min ;
	return 0;
}