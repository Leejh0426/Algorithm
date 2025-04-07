#include<bits/stdc++.h>
#define size aa
using namespace std;

int sum1, sum2;
int size, n, m;
vector<int> v1;
vector<int> v2;
int ret;

int arr[1000004];


void go1() {

		int sum = 0;
		for (int i = 0; i < m; i++) {
			sum = 0;
			for (int k = i; k < m-1+i; k++) {
				sum += v1[k%m];
				if (sum < size) { arr[sum] += 1; }
				else if (sum == size) {
					ret++;
					break;
				}
				else {
					break;
				}
			}
		}
		if (sum1 < size)arr[sum1] += 1;
		else if (sum1 == size) ret++;

		for (int i = 0; i < n; i++) {
			sum = 0;
			for (int k = i; k < n - 1 + i; k++) {
				sum += v2[k%n];
				if (sum < size) ret+=arr[size-sum];
				else if (sum == size) {
					ret++;
					break;
				}
				else {
					break;
				}
			}
		}
		if (sum2 < size) ret += arr[size - sum2];
		else if (sum2 == size)ret++;

		
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> size >> m >> n;

	int temp;

	for (int i = 0; i < m; i++) {
		cin >> temp;
		v1.push_back(temp);
		sum1 += temp;
	}



	//---------

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v2.push_back(temp);
		sum2 += temp;
	}

	
	go1();



	cout << ret;

	return 0;
}