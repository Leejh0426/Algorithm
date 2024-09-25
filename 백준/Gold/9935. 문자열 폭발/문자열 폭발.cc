#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define y1 aaa
#define ll long long

string s;
string bomb;
deque<char> deq;
string temp;
bool flag;
bool endflag;
int cnt;
int main() {

	cin >> s >> bomb;
	
	reverse(bomb.begin(), bomb.end());
	//cout << "bomb:" << bomb<<"\n";

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		deq.push_back(c);
		int len = bomb.length();
		if (c == bomb.front() && deq.size() >= bomb.length()) {
			temp = "";
			while (len--) {
				temp += deq.back();
				deq.pop_back();
			}
			//cout << temp<<"\n";
			if (temp == bomb) continue;
			else {
				reverse(temp.begin(), temp.end());
				for (char c : temp) {
					deq.push_back(c);
				}
			}

		}

		

	}




	if (!deq.empty()) {
		for (char c : deq) {
			cout << c;
		}
	}
	else {
		cout << "FRULA";
	}


	return 0;
}