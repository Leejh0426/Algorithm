#include <bits/stdc++.h> 
#define MAX_N 

typedef long long ll;
using namespace std;

const ll INF = 987654321;
ll n;
double m;
int M;

ll dp[10001];

int main(){
    
    while (true) {
        cin >> n >> m;
        M = (int) (100.0 * m + 0.5);
        if (n == 0) break;
        
        fill(&dp[0], &dp[0] + 10001, 0);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            ll cal;
            double m1;
            cin >> cal >> m1;
            int M1 = (int)(m1*100.0+0.5);
      
            for (int j = M1; j <= M; j++) {
                dp[j] = max(dp[j], cal + dp[j - M1]);
            }
        }
        
       cout << dp[M] << '\n';

    }


    return 0;
}
