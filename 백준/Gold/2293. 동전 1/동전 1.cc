#include <bits/stdc++.h> 
#define MAX_N 

typedef long long ll;

const int INF = 987654321;
const int max_int = 100001;
using namespace std;


int n, k;
ll dp[max_int];
vector<int> coin;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    fill(&dp[0], &dp[0] + max_int, 0);
    dp[0] = 1;
    int temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        coin.push_back(temp);
    }
    
    sort(coin.begin(), coin.end());
   
    for (int i = 0; i < n; i++) {
        if (i == 0) {
           
            for (int j = coin[i]; j <= k; j+=coin[i]) {
                dp[j] = 1;
            }
            continue;
        }
        temp = coin[i];
        
        for (int j = temp; j <= k; j++) {
            dp[j] += dp[j - temp];
        }

       /* for (int j = 0; j <= k; j++) {
            cout << dp[j] << " ";
        }*/
        //cout << "\n ";
        //cout << "i : " << i << '\n';
        //cout << "coin[i] : " << coin[i] << '\n';
        //cout << "Ekq : " << dp[k] << '\n';
    }

    cout << dp[k];

    return 0;
}
