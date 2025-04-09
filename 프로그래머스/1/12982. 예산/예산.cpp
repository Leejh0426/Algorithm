#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> d, int bu) {
    int answer = 0;
    sort(d.begin(),d.end());
    int budget = bu;
    for(int i=0; i<d.size(); i++){
        if(budget>=d[i]){
            answer++;
            budget-=d[i];
        }else{
            break;
        }
    }
    return answer;
}