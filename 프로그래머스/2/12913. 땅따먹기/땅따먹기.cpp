#include <iostream>
#include <vector>
#include <bits/stdc++.h>


int arr[100004][4];
using namespace std;
int answer;

int solution(vector<vector<int> > land)
{
    for(int i=1; i<=land.size(); i++){
        for(int j=1; j<=land[i-1].size();j++){
            int temp=0;
            for(int k=0; k<4; k++){
                if(k!=j-1) temp = max(arr[i-2][k],temp);
            }
            arr[i-1][j-1] = temp+land[i-1][j-1];
            answer=max(answer,arr[i-1][j-1]);
        }    
    }
    
    return answer;
}