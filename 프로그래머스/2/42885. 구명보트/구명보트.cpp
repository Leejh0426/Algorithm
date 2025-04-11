#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
int answer;

int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end(),greater<>());
    int j = people.size();
    for(int i=0; i<j;i++){
        int siz = people[i];
        while(true){
            if(i>=j-1) break;
            if(siz+people[j-1]<=limit){ siz+=people[j--]; }
            break;
        }
        answer++;
    }
    return answer;
}