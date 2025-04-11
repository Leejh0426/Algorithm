#include<bits/stdc++.h>


using namespace std;
int n;

int main(){
	cin >> n;
	cin.ignore();
	string s1;
	string s2;
	while (n--) {
		getline(cin, s1,'\n');
		getline(cin, s2,'\n');
		
		vector<string> v1;
		vector<string> v2;
		string ret = "The two trees are isomorphic.";
		string s="";
		int cnt = 0;
		for (int i = 1; i < s1.size()-1; i++) {
			if (s1[i] == ' ') continue;
			else if (s1[i] != '#') {
				cnt++;
				s += "a";
			}
			else {
				cnt--;
				s1[i] += '#';
			}

			if (cnt == 0) {
				v1.push_back(s);
				s = "";
				cnt = 0;
			}
		}

		for (int i = 1; i < s2.size() - 1; i++) {
			if (s2[i] == ' ') continue;
			else if (s2[i] != '#') {
				cnt++;
				s += "a";
			}
			else {
				cnt--;
				s2[i] += '#';
			}
			if (cnt == 0) {
				v2.push_back(s);
				s = "";
				cnt = 0;
			}
		}

		if (s1.size() != s2.size()) {
			ret = "The two trees are not isomorphic.";
		}

		for (int i=0; i<v1.size();i++){
			bool flag = false;
			for (int j = 0; j < v2.size(); j++) {
				if (v1[i] == v2[j]) { 
					flag = true;
					v2[j] = "";
				}
			}
			if(!flag) ret = "The two trees are not isomorphic.";
		}
		cout << ret << '\n';

	}

	return 0;
}