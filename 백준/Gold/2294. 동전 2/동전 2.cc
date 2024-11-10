#include <bits/stdc++.h> 
#define MAX_N 

typedef long long ll;

const int INF = 987654321;
const int max_int = 100001;
using namespace std;


int n,k;
ll dp[max_int];





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n>>k;

    fill(&dp[0], &dp[0] + max_int, INF);

    int temp;
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        dp[temp] = 1;
        for (int j = temp; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - temp] + 1);
        }

    }


    if (dp[k] != INF)cout << dp[k];
    else cout << -1;

    return 0;
}
