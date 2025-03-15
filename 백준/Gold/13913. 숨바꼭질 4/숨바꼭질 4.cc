#include <bits/stdc++.h>

using namespace std;

int n, k;

const int max_n = 100004;

int visited[max_n];
int ret;


void bfs() {
	queue<int> q;
	q.push(n);
	while (true) {
		ret++;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {

			int here = q.front();
			q.pop();

			if (here == k) return;

			if (here+1 <max_n && visited[here + 1] == -2) {
				q.push(here + 1);
				visited[here + 1] = here;
			}
			if (here *2 < max_n && visited[here * 2] == -2) {
				q.push(here * 2);
				visited[here * 2] = here;
			}
			if (here - 1 >= 0 && here-1 < max_n && visited[here - 1] == -2) {
				q.push(here - 1);
				visited[here - 1] = here;
			}
		}
	}
}


int main() {
	cin >> n >> k;

	fill(&visited[0], &visited[0]+ max_n, -2);

	visited[n] = -1;
	bfs();
	cout << ret - 1 << '\n';

	vector<int> v;
	v.push_back(k);
	int temp = k;

	while (true) {
		if (visited[temp] != -1) {
			temp = visited[temp];
			v.push_back(temp);
		}
		else {
			break;
		}
	}

	reverse(v.begin(), v.end());

	for (int i : v) cout << i << ' ';

	return 0;
}