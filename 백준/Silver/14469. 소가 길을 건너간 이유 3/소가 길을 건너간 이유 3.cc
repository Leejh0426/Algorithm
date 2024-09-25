#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;


int main() {
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	int ret = 0;
	for (pair<int, int> p : v) {
		int arriveTime = p.first;
		int checkTime = p.second;

		if (ret > arriveTime) {
			ret += checkTime;
		}
		else {
			ret = arriveTime + checkTime;
		}
	}

	cout << ret;
	
}