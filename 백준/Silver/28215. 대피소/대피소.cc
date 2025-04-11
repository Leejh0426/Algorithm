#include<bits/stdc++.h>

using namespace std;

int n, k;
int ret=INT_MAX;
vector<pair<int, int>> vp;

void go(int here, vector<int> v) {
	if (v.size() == k) {
		int max_num = 0;
		for (int i = 0; i < vp.size(); i++) {
			int ny = vp[i].first;
			int nx = vp[i].second;
			int min_num=987654321;
			for (int j = 0; j < v.size(); j++) {
				min_num = min(min_num, abs(ny-vp[v[j]].first)+abs(nx-vp[v[j]].second));
			}
			max_num = max(max_num, min_num);
		}
		ret = min(ret, max_num);
		return;
	}
	if (here == vp.size()) return;

	go(here + 1, v);
	v.push_back(here);
	go(here + 1, v);
}



int main(){
	cin >> n >> k;

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		vp.push_back({ y,x });
	}
	vector<int> v;
	go(0,v);

	cout << ret;

	return 0;
}