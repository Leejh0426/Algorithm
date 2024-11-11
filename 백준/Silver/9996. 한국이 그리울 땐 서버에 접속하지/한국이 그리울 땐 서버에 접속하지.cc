#include <bits/stdc++.h>


using namespace std;

int n;

string s;
string s_front;
string s_end;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> s;
	s_front = s.substr(0, s.find("*"));
	s_end = s.substr(s.find("*")+1, s.length());
	
	string ts;
	for (int i = 0; i < n; i++) {
		cin >> ts;
		//cout << ts.substr(0, s.find("*")) << '\n';
		//cout << ts.substr(ts.length()-(s.length()-1 - s.find("*")), ts.length()) << '\n';
		if (ts.length() + 1 < s.length()) {
			cout << "NE\n";
			continue;
		}
		if ((ts.substr(0, s.find("*")) == s_front) && (ts.substr(ts.length() - (s.length() - 1 - s.find("*")), ts.length()) == s_end)) {
			cout << "DA"<<"\n";
			continue;
		}
		cout << "NE"<<"\n";
	}



	return 0;
}


