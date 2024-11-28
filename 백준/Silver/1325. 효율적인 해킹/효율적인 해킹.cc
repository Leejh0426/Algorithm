#include <bits/stdc++.h>
using namespace std;


const int max_int = 10001;
int n, m;

vector<int> v[max_int];
int visited[max_int];

int max_count = 1;

vector<int> retV;




int dfs(int num) {
	visited[num] = 1;
	int ret = 1;

	for (int n : v[num]) {
		if (!visited[n])
			ret += dfs(n);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int x;
	int y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		fill(&visited[0], & visited[0] + max_int, 0);
		int ret = dfs(i);
	/*	cout << "i : " << i << " ret : " << ret << '\n';*/
		if (ret == max_count) retV.push_back(i);
		else if (ret > max_count) {
			max_count = ret;
			retV.clear();
			retV.push_back(i);
		}
	}


	sort(retV.begin(), retV.end());

	for (int a : retV) {
		cout << a << " ";
	}

	return 0;

}