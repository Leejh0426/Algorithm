#include <bits/stdc++.h>


using namespace std;

string s;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (true) {
		getline(cin, s);
		stack<char> stk;
		bool flag = true;
		
		if (s == ".") break;

		for (char c : s) {
			if (c == '(' || c == '[') {
				stk.push(c);
			}
			else if (c == ')') {
				if (stk.empty() || stk.top() != '(') flag = false;
				else {
					stk.pop();
				}
			}
			else if (c == ']') {
				if (stk.empty() || stk.top() != '[') flag = false;
				else {
					stk.pop();
				}
			}
		}

		if (!stk.empty()) flag = false;

		if (flag) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}

	
	return 0;

}



