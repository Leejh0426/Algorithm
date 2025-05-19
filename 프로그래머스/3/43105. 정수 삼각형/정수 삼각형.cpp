#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int arr[504][504];

int answer=INT_MIN;

int solution(vector<vector<int>> triangle) {
    for(int i=0; i<triangle.size(); i++){
        for(int j=0; j<triangle[i].size();j++){
            arr[i+1][j+1]=max(arr[i][j],arr[i][j+1])+triangle[i][j];

        }
    }
  
    for(int i=0; i<triangle[triangle.size()-1].size();i++){
        answer= max(answer,arr[triangle.size()][i]);        
    }

    return answer;
}