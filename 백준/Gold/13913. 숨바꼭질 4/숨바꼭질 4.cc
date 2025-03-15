#include <bits/stdc++.h>
using namespace std;
#define prev aaa

const int max_int = 200000;

int visited[max_int + 4];

int prev[max_int+4];

queue<int> q;
vector<int> v;

int n, k,ret;



int main() {
	cin >> n >> k;
	if (n == k) {
		cout << "0" << "\n";
		cout << n;
		return 0;
	}
	visited[n] = 1;
	q.push(n);

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		if (num == k) {
			ret = visited[k];
			break;
		}
		for (int next : {num - 1, num + 1, num * 2}) {
			if (next >= 0 && next < 200000) {
				if (!visited[next]) {
					q.push(next);
					visited[next] = visited[num] + 1;
					prev[next] = num;
				}
				
			}
		}

	}
	
	for (int i = k; i != n; i = prev[i]) {
		v.push_back(i);
	}
	v.push_back(n);

	cout << ret - 1 << "\n";
	reverse(v.begin(), v.end());
	for (int i : v) cout << i << ' ';

	return 0;
}
