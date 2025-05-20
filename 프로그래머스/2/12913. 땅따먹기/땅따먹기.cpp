#include <iostream>
#include <vector>
#include <bits/stdc++.h>


int arr[100004][4];
using namespace std;
int answer;

int solution(vector<vector<int> > land)
{
    int n=land.size();
    
    arr[0][0] = land[0][0];
    arr[0][1] = land[0][1];
    arr[0][2] = land[0][2];
    arr[0][3] = land[0][3];
    
    
    for(int i=1; i<n; i++)
    {
        for(int j=0;j<4;j++)
        {
            int max_num=0;
            for(int k=0; k<4; k++)
            {
                if(k==j) continue;
                max_num = max(max_num, arr[i-1][k]);
            }
            arr[i][j] = max_num + land[i][j];
        }
    }
    for(int i=0; i<4; i++){
        answer = max(answer, arr[n-1][i]);
    }
    return answer;
}