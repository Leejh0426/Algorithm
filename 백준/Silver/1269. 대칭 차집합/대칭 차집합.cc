#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;

int ret;
map<int, int> _map;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp; 
        _map[temp]++;

    }
    for (int j = 0; j < m; j++) {
        cin >> temp; 
        _map[temp]++;
    }
    for (auto it : _map) {
        if (it.second == 1)ret++;
    }
    
    cout << ret;

    return 0;
}