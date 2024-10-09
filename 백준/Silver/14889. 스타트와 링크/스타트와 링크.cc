#include <bits/stdc++.h>
using namespace std;

const int max_int = 100;

int n;
int ret = 987654321;
int a[max_int][max_int];

int summ(vector<int> v) {
	int sum=0;
	for (int i = 0; i < n / 2;i++) {
		for (int j = i + 1; j < n / 2; j++) {
			sum += a[v[i]][v[j]];
			sum += a[v[j]][v[i]];
		}
	}
	return sum;
}

void combi(int a, vector<int> v) {
	if (v.size() == n / 2) {
		vector<int> v2;
		for (int i = 0; i < n; i++) {
			if (find(v.begin(), v.end(), i) == v.end()) v2.push_back(i);
		}
		int ret1 = summ(v);
		int ret2 = summ(v2);
		ret = min(ret, abs(ret1-ret2));
	}

	for (int i = a+1; i < n; i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> v;
	combi(-1, v);

	cout << ret;

	return 0;

}

/* --1
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int s[24][24], ret = INF, n; 
int go(vector<int>& a, vector<int> & b){
	pair<int, int> ret;  
	for(int i = 0; i < n / 2; i++){
		for(int j = 0; j < n / 2; j++){
			if(i == j)continue;
			ret.first += s[a[i]][a[j]];
			ret.second += s[b[i]][b[j]]; 
		}
	}
	return abs(ret.first - ret.second);
}
int main() { 
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    } 
    for (int i = 0; i < (1 << n); i++) {
		if(__builtin_popcount(i) != n / 2) continue; 
        vector<int> start, link;
		for(int j = 0; j < n; j++){
			if(i & (1 << j))start.push_back(j);
			else link.push_back(j);
		}
		ret = min(ret, go(start, link)); 
    }
    cout << ret << '\n';
} 
/*

/* --2
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int s[24][24], ret = INF, n; 
int k = 10, visited[24];
vector<int> v; 
int go(vector<int>& a, vector<int> & b){
	pair<int, int> ret;  
	for(int i = 0; i < n / 2; i++){
		for(int j = 0; j < n / 2; j++){
			if(i == j)continue;
			ret.first += s[a[i]][a[j]];
			ret.second += s[b[i]][b[j]]; 
		}
	}
	return abs(ret.first - ret.second);
} 
void combi(int start, vector<int> b){ 
    if(b.size() == k){ 
        vector<int> start, link; 
        for(int i = 0; i < n; i++){
        	if(visited[i])start.push_back(i);
        	else link.push_back(i);
		} 
		ret = min(ret, go(start, link)); 
        return;
    }
    for(int i = start + 1; i < n; i++){ 
        visited[i] = 1;
        b.push_back(i);
        combi(i, b);
        visited[i] = 0; 
        b.pop_back();
    }
    return;
}  

int main() { 
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    } 
    k = n / 2;
	vector<int> v;  
    combi(-1, v);  
    cout << ret << '\n';
} 

*/
