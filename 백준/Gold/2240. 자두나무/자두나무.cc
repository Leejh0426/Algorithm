#include <bits/stdc++.h>

const int max_int = 52;

using namespace std;
typedef long long ll;

int t, w;
ll dp[1001][31][2];

int peach[1001];

ll go (int time,int moveCount, int location) {
	if (time == t) {
		return 0;
	};
	
	ll& ret1 = dp[time][moveCount][location];
	if (ret1 != -1) return ret1;
	if (moveCount == w) {
		ret1 = max(ret1, go(time + 1, moveCount, location)) + (peach[time] == location);
		return ret1;
	}
	ll temp = max(go(time + 1, moveCount, location), go(time + 1, moveCount + 1, location ^ 1));
	ret1 = max(ret1,temp) + (peach[time]==location);

	return ret1;
}

int main() {
	
	cin >> t >> w;

	for (int i = 0; i < t; i++) {
		cin >> peach[i];
		peach[i]--;
	}
	memset(dp, -1, sizeof(dp));
	cout << max(go(0,0,0), go(0, 1, 1));

	return 0;
	
}
