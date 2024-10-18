#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, m;


int temp;
vector<int> v1;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
 
        v1.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            v1.push_back(temp);
        }
        sort(v1.begin(), v1.end());
        cin >> m;

        for (int i = 0; i < m; i++) {
            cin >> temp;
            int left = 0, right = v1.size() - 1;
            int mid;
            bool flag = false;
            while (left <= right) {
                mid = (left + right) / 2;
                if (v1[mid] == temp) {
                    cout << "1" << '\n';
                    flag = true;
                    break;
                }
                else if (v1[mid] > temp) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            if (!flag) cout << "0" << "\n";
            
        }

    }


    return 0;

}