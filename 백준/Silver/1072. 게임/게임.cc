#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll x, y, z;


ll answer=-1;

bool check(ll mid) {
    
    int tempZ = (y+mid) * 100 / (x + mid);
  //  cout << "mid : " << mid << "  tempZ : " << tempZ << " Z : " << z << "\n";
    if (tempZ != z) return true;
    else return false;
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> x >> y;

    z = y * 100 / x;
   

    

    ll left=1, right=1e13,mid;
    

    while (left <= right) {
        mid = (left + right) / 2;
        if (check(mid)) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;

}