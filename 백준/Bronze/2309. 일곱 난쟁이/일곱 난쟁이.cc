#include<bits/stdc++.h>

using namespace std;

int k = 7, n = 9;
int sum = 0;

void print(vector<int> b) {
    sort(b.begin(), b.end());
    for (int i : b)cout << i << "\n";
}

void combi(int start, vector<int> b,int * arr) {
    if (b.size() == k) {
        for (auto iter = b.begin(); iter < b.end(); iter++) {
            sum += *iter;
        }
        if (sum == 100) {
            print(b);
            exit(0);
        }
        sum = 0;
        return;
    }
    for (int i = start + 1; i < n; i++) {
        b.push_back(arr[i]);
        combi(i, b, arr);
        b.pop_back();
    }
    return;
}

int main() {
    int arr[9];

    int temp=0;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr[i] = temp;
    }
    vector<int> b;

    combi(-1, b,arr);

    
    return 0;
}

