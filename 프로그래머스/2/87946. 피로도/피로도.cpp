#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int ret;
vector<vector<int>> dungeonss;
int visited[9];
bool flag;

void go(int k, int cnt){
    flag = false;
    
    for(int i=0;i<dungeonss.size();i++){
       if(dungeonss[i][0] > k) continue;
        if(visited[i]==1) continue;
        visited[i]=1;
        go(k-dungeonss[i][1],cnt+1);
        visited[i]=0;
        flag = true;
    }
    if(!flag){ret=max(ret,cnt); return;}
}


int solution(int k, vector<vector<int>> dungeons) {
    dungeonss=dungeons;
    go(k,0);
    int answer = ret;
    return answer;
}

