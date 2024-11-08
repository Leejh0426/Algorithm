#include <bits/stdc++.h>

const int max_int = 52;

using namespace std;
typedef long long ll;

int n;

ll dp[31][31];


ll go(string s, int h_number, int w_number) {
	if (s.length() == n*2) {
	//	cout << s << '\n';
		if (h_number == w_number) return 1;
		else return -1e9;

	}
	/*ll ret = dp[s];
	if (ret != 0) return ret;*/
	
	ll& ret = dp[h_number][w_number];
	if (ret != -1) return ret;

	if (w_number < n) {
		if (w_number > h_number) ret = max(ret, go(s + "H", h_number + 1, w_number) + go(s + "W", h_number, w_number + 1));
		else ret = max(ret,go(s + "W", h_number, w_number + 1));
	}
	else ret = max(ret, go(s + "H", h_number+1, w_number));


	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		if (n == 0) exit(0);
		cout << go("W", 0, 1)<<'\n';
	}

	return 0;
	
}

