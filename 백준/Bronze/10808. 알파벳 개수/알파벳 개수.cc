#include<bits/stdc++.h>

using namespace std;


int arr[26];
string str;

int main() {
    
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        arr[str[i] - 97]++;
    }

    for (int i = 0; i < 26; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
