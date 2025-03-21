#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define y1 aaa

const int max_num = 15;


vector<int> adj[11];

int comp[max_num];
int visited[max_num];
int n;


int a[max_num];

int ret=99999;


pair<int, int> dfs(int here, int value) {
	visited[here] = 1;
	pair<int, int> ret = { 1, a[here] };
	for (int there : adj[here]) {
		if (comp[there] != value) continue;
		if (visited[there]) continue;
		pair<int, int> _temp = dfs(there, value);
		ret.first += _temp.first;
		ret.second += _temp.second;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	

	for (int i = 0; i < n; i++) {
		int count;
		int temp;
		cin >> count;
		for (int j = 0; j < count; j++) {
			cin >> temp;
			adj[i].push_back(temp-1);
			adj[temp-1].push_back(i);
		}
	}

	for (int i = 1; i < (1 << n)-1; i++) {
		fill(comp, comp + max_num, 0);
		fill(visited, visited + max_num, 0);
		int idx1 = -1, idx2 = -1;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) { comp[j]=1; idx1 = j; }
			else idx2 = j;
		}
		pair<int, int> comp1 = dfs(idx1, 1);
		pair<int, int> comp2 = dfs(idx2, 0);

		if (comp1.first + comp2.first == n) ret = min(ret, abs(comp1.second - comp2.second));
	}
	
	
	if (ret == 99999) cout << -1;
	else cout << ret;

	return 0;
	
}