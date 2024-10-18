#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, m;


int temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        map<int, bool> _map;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            _map[temp] = true;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> temp;
            if (_map[temp]) cout << "1" << '\n';
            else cout << "0" << "\n";
        }

    }


    return 0;

}