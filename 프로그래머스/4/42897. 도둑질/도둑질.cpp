#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int answer = 0;

int arr[3][1000004];
int solution(vector<int> money) {
    int cnt = 0;
    while(cnt<=2){
        
        arr[cnt][0] = money[0];
        arr[cnt][1] = money[0];
        
        for(int i=2; i<money.size();i++){
            arr[cnt][i] = max(arr[cnt][i-2]+money[i] , arr[cnt][i-1]);
        }
        
        
        cnt++;
        rotate(money.begin(), money.begin()+1, money.end());
    }
    answer = max({arr[0][money.size()-2],arr[1][money.size()-2],arr[2][money.size()-2]});
    
    return answer;
        
}