#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int arr[1004][1004];
int answer;
int solution(vector<vector<int>> board)
{
    
    
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[0].size();j++)
        {
            if(i==0 || j==0) arr[i][j] = board[i][j];
            else{
                if(board[i][j]) arr[i][j] = min({arr[i-1][j] , arr[i][j-1], arr[i-1][j-1]}) + 1;
                else arr[i][j] = 0;
            }
            answer = max(answer, arr[i][j]);
        }
    }
   
    answer = pow(answer,2);
    return answer;
}