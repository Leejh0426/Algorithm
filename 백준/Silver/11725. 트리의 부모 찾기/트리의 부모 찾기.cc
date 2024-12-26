#include <bits/stdc++.h>

using namespace std;

const int max_int = 1000001;

bool visited[max_int];
vector<int> v[max_int];

int n;

int ret[max_int];


void dfs(int node) {
	visited[node] = true;

	for (int a : v[node]) {
		if (visited[a]) continue;
		ret[a] = node;
		dfs(a);
	}

	return;
}


int main() {

	cin >> n;

	int a, b;

	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i < n+1; i++) {
		cout << ret[i] << '\n';
	}

	return 0;
}