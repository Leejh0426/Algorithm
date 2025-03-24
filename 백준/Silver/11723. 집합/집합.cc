#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<map>
#include<bits/stdc++.h>

using namespace std;

const int max_int = 52;

int m;
//bool a[21];
int a;
string s;
int temp;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (s.compare("add") == 0) {
			cin >> temp;
			a |= (1 << temp);
		}
		else if (s.compare("remove") == 0) {
			cin >> temp;
			a &= ~(1 << temp);
		}
		else if (s.compare("check") == 0) {
			cin >> temp;
			if (a & (1<<temp)) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (s.compare("toggle") == 0) {
			cin >> temp;
			a ^= (1 << temp);
		}
		else if (s.compare("all") == 0) {
			a |= (1<<21)-1;
		}
		else if (s.compare("empty") == 0) {
			a &= ~((1 << 21) - 1);
		}
		
	}
	

	return 0;
	
	

}
