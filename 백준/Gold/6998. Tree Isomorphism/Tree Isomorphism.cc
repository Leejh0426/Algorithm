#include <bits/stdc++.h>
using namespace std;

map<string, int> m;


int t;



string s;
string s1, s2;
int cnt;
int main() {
	cin >> t;
	cin.ignore();
	
	while (t--) {
		m.clear();
		bool flag = true;
		getline(cin, s1);
		getline(cin, s2);
		cnt = 0;
		int count0 = 0;
		int count1 = 0;
		s = "";
		for (int i = 1; i < s1.size() - 1;i++) {
			if (s1[i] == ' ') continue;

			if (s1[i] == '#') {
				s += "1";
				count1++;
			}
			else {

				s += "0";
				count0++;
			}

			if (count0 == count1) {

				m[s]++;
				cnt++;
				count0 = 0;
				count1 = 0;
				s = "";
			}
		}

		count0 = 0;
		count1 = 0;
		s = "";
		for (int i = 1; i < s2.size() - 1; i++) {
			if (s2[i] == ' ') continue;

			if (s2[i] == '#') {
				s += "1";
				count1++;
			}
			else {

				s += "0";
				count0++;
			}

			if (count0 == count1) {
				if (m.find(s) != m.end() && m[s] > 0) {
					m[s]--;
					cnt--;
				}
				else {
					flag = false;
					break;
				}
				count0 = 0;
				count1 = 0;
				s = "";
			}
		}


		if (flag && !cnt) cout << "The two trees are isomorphic.\n";
		else cout << "The two trees are not isomorphic.\n";
	}
	

	

	return 0;

}