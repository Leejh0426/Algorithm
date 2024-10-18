#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s, c,l;
ll pa[1000001];
ll chicken[1000001];
ll answer;

ll ramen_answer;

bool check(ll mid) {
    ll ret = 0;

    for (int i = 0; i < s; i++) {
        ret += pa[i] / mid;
    }
   // cout << "mid : " << mid << " ret : " << ret << "\n";

    return ret >= c;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> s >> c;

    ll left = 1, right = -1, mid;

    for (int i = 0; i < s; i++) {
        cin >> pa[i];
        right = max(right, pa[i]);
    }

    while (left <= right) {
        mid = (left + right) / 2;
        if (check(mid)) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
            
        }

    }

    
    
    for (int i = 0; i < s; i++) {
        ramen_answer += pa[i];
    }
    ramen_answer -= answer * c;
    cout << ramen_answer;

    return 0;

}