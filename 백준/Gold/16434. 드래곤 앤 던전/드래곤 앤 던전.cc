#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, H_ATK, H_MAXHP,H_CURHP, ti, ai, hi;

vector<pair<long long, pair<long long, long long> > > v;

long long temp_ATK;
long long temp_HP;
long long temp_MAX_HP;

long long answer= LLONG_MAX;

bool check(ll mid) {
    ll temp_ATKK = H_ATK;
    ll temp_MAX_HP = mid;
    ll temp_HP = mid;

    for (pair<ll,pair<ll,ll> > p : v) {
        if (p.first == 1) {
          //  cout << "tempHP: " << temp_HP << "\n";
            temp_HP-=(p.second.second / temp_ATKK)* p.second.first;
            if (!(p.second.second % temp_ATKK)) temp_HP += p.second.first;
        }
        else {
            temp_HP = min(temp_HP+p.second.second,temp_MAX_HP);
            temp_ATKK += p.second.first;

        }
        if (temp_HP <= 0) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll left=0, right=1,mid;

    cin >> n >> H_ATK;

    temp_ATK = H_ATK;
    for (int i = 0; i < n; i++) {
        cin >> ti >> ai >> hi;
        v.push_back({ ti,{ai,hi} });
        if (ti == 1) {
            right += (hi / temp_ATK) * ai;
            //if (!(hi % temp_ATK)) right -= ai;
        }
        else {
            temp_ATK += ai;
        }
      //  cout << "left : " << left << " right : " << right << "\n";
    }

   
    while (left <= right) {
        mid = (left + right) / 2;
     //   cout << "mid : " << mid << "\n";
        if (check(mid)) {
            answer = min(answer, mid);
            right = mid - 1;
           // cout << "success" << "\n";
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;

}