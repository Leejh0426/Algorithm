#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000001];

int goal;
int ret;

vector<int> v;
int main() {

	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	
	cin >> goal;
	
	sort(v.begin(), v.end());

	int lo = 0;
	int hi = n-1;

	while (true) {
		if (lo == hi) break;
		int temp_g = v[lo] + v[hi];
		if (temp_g== goal) { ret++; lo++; }
		else if (temp_g > goal) { hi--; }
		else if (temp_g < goal) { lo++; }
	}
	
	cout << ret;
	return 0;

}