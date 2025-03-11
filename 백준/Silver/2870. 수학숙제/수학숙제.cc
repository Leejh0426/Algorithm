#include <bits/stdc++.h>
using namespace std;


int n;
vector<string> v;
string str;

int cmp(string a, string b) {
	if (a.length() > b.length()) return 0;
	else if (a.length() == b.length()) {
		for (int i = 0; i < a.length(); i++) {
			if ((a[i]) > b[i]) return 0;
			else if (a[i] < b[i]) return 1;
			else continue;
			
		}
	}
	else return 1;
	return 0;
	
}

int main() {
	cin >> n;


	for (int t = 0; t < n; t++) {

		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			int j = i;
			string str2;
			int flag = 0;
			if (str[i] >= '0' && str[i] <= '9') {
				while (j < str.length() && str[j] >= '0' && str[j] <= '9') {
					j++;
				}
				for (int k = i; k < j; k++) {
					if (j - k > 1 && str[k]=='0' && flag==0 && (k<j-1) )
						continue;
					str2 += str[k];
					flag = 1;
				}
				v.push_back(str2);
				i = j;
			}

		}

	}

	sort(v.begin(), v.end(),cmp);



	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << "\n";
	}



	return 0;
}
