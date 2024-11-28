#include <bits/stdc++.h>
using namespace std;

const int max_int = 1000001;

int n;
int a[max_int];

int ret[max_int];

stack<pair<int, int>> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (!s.empty()) {
			while (true) {
				if (s.empty()) break;
				pair<int, int> p = s.top();
				if (p.second >= temp) {
					break;
				}
				s.pop();
				ret[p.first] = temp;
			}
		}
		s.push({ i,temp });
	}

	while (true) {
		if (s.empty()) {
			break;
		}
		pair<int, int> p = s.top();
		s.pop();
		ret[p.first] = -1;
	}

	for (int i = 0; i < n; i++) {
		cout << ret[i] << " ";
	}

	return 0;

}