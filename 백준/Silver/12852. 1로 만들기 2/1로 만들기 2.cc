#include <bits/stdc++.h>

const int max_int = 52;

using namespace std;
typedef long long ll;


int n;

int INF = 987654321;
ll dp[1000001];
int cnt = 0;
ll go(int n) {
	if (n == 0) {
		return 1;
	}

	ll& ret = dp[n];
	if (ret != -1) return ret;

	ret = INF;
	if (!(n % 3)) ret = min(ret, go(n / 3) + 1);
	if (!(n % 2)) ret = min(ret, go(n/2) + 1);
	ret = min(ret, go(n-1) + 1);

	return ret;
	
}

void gogo(int n) {
	if (n < 1) {
		return;
	}
	cout << n << " ";

	if ( !(n % 2) && dp[n / 2] == dp[n] - 1) gogo(n / 2);
	else if (!(n % 3) && dp[n / 3] == dp[n] - 1) gogo(n / 3);
	else gogo(n - 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	cout<<go(n)-2<<'\n';

	gogo(n);


	return 0;

}


