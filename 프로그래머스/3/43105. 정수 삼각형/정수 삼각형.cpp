#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int arr[504][504];


int solution(vector<vector<int>> triangle) {
    
    int answer = 0;
    
    for(int i=1; i<=triangle.size(); i++){
        for(int j=1; j<=triangle[i-1].size(); j++){
            int temp = 0;
            temp = max(temp, arr[i-1][j-1]);
            temp = max(temp, arr[i-1][j]);
            arr[i][j]= temp + triangle[i-1][j-1];            
            answer = max(answer, arr[i][j]);
        }
    }
    
    return answer;
}