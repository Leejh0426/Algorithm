#include<bits/stdc++.h>

using namespace std;


const int max_int = 20001;

int t, n, m;

int a[max_int];
int b[max_int];


int main() {

	cin >> t;

	while (t--) {
		int ret = 0;
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}

		
		sort(&a[0], &a[0] + n);
		sort(&b[0], &b[0] + m);

		int j = 0;
		int i = 0;
		while(i<n){
			if (a[i] <= b[j]) {
				ret += j;
				i++;
			}
			else {
				if(j<m)j++;
				else { 
					ret += j; 
					i++;
				}
			}
		}
		

		cout << ret << "\n";
	}
	

	return 0;
}
