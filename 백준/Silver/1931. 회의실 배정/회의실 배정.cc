#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;
int ret;


int main() {
	cin >> n;

	int start, end;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v.push_back({ end,start });
	}

	sort(v.begin(), v.end());


	int lastEnd=0;

	for (pair<int, int>p : v) {
		int start = p.second;
		int end = p.first;
		if (lastEnd <= start) {
			ret++;
			lastEnd = end;
		}

	}

	cout << ret;
	return 0;
	
}