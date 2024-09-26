#include<bits/stdc++.h>

using namespace std;

int n, k;
vector<pair<int, int>> gold;
vector<int> bag;

priority_queue< int > pq;

long long ret;
bool flag;

int main() {
	cin >> n >> k;
	int m, v, c;
	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		gold.push_back({ m,v });
	}
	for (int i = 0; i < k; i++) {
		cin >> c;
		bag.push_back(c);
	}

	sort(gold.begin(), gold.end());
	sort(bag.begin(), bag.end(),greater<>());


	//cout << bag.front() << "\n";
	//cout << bag.back() << "\n";
	c = bag.back();
	bag.pop_back();

	int cnt = 1;
	for (pair<int, int> p : gold) {

		m = p.first;
		v = p.second;

	/*	cout << "c<<" << c << "\n";
		cout << "m<<" << m << "\n";
		cout << "v<<" << v << "\n";*/

		while (c < m) {
			if (!pq.empty()) { ret += pq.top(); pq.pop(); }
			if (bag.empty()) {
				flag = true;
				break;
			}
			c = bag.back();
	/*		cout << "----c" << c << "\n";*/
			bag.pop_back();
		}

		if (flag) break;
		pq.push(v);
	}

	if (!flag) {
		if (!pq.empty()) {
			ret += pq.top();
			pq.pop();
		}
	}

	while (bag.size()) {
		bag.pop_back();
		if (!pq.empty()) { ret += pq.top(); pq.pop(); }
	}

	cout << ret;
	return 0;
}