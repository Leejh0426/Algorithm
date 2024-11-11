#include <bits/stdc++.h>

const int max_int = 100001;
using namespace std;
typedef long long ll;

ll a, b, c;



ll go(ll a, ll b) {
	if (b == 1) {
		return a % c;
	}

	ll ret = go(a, b / 2);
	ret = (ret%c * ret%c) % c;
	if (b % 2) ret = (ret % c * a % c) % c;
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b >> c;
	
	cout<<go(a, b);
	

	
	return 0;
}


