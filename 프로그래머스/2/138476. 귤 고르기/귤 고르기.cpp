#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
int answer;

int solution(int k, vector<int> tangerine) {
    vector<int> v;
    sort(tangerine.begin(), tangerine.end());
    for(int i=0; i<tangerine.size();i++){
        int cnt = 1;
        while(true){
            if(i==tangerine.size()){
                v.push_back(cnt);
                break;
            }
            if(tangerine[i]==tangerine[i+1]){
                cnt++;
                i++;
            }else{
                v.push_back(cnt);
                break;
            }
        }       
    }
    
    sort(v.begin(),v.end(),greater<int>());
    
    int size = k;
    
    for(int i=0; i<v.size();i++){
        if(size==0) break;
        else if(size>=v[i]){
            size-=v[i];
            answer++;
        }else if(size<v[i]){
            answer++;
            break;
        }
    }
    
    
    return answer;
}