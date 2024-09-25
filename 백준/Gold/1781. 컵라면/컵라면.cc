#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;
priority_queue<int,vector<int>, greater<int>> pq;

int ret;

int main() {
	cin >> n;

	int deadline;
	int ramenCount;
	for (int i = 0; i < n; i++) {
		cin >> deadline >> ramenCount;
		v.push_back({ deadline,ramenCount });
	}
	sort(v.begin(), v.end());

	for (pair<int, int>p : v) {
		pq.push(p.second);
		if (p.first < pq.size()) {
			pq.pop();
		}
	}
	while (!pq.empty()) {
		int temp = pq.top();
		pq.pop();
		ret += temp;
	}
	cout << ret;
	return 0;
}