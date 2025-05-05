#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int eraseCnt;
int cnt;

string erase1(string s){
    string str="";
    for(int i=0; i<s.size(); i++){
        if(s[i]=='1') str+="1";
        else eraseCnt++;
    }

    return str;
}

string BinaryChange(string s){
    string str="";
    int size = s.size();
    while(true){
        if(size==0) break;
        if(!(size%2)) str+="0";
        else str+="1";
        size/=2;
    }
    return str;
}

vector<int> solution(string abc) {

    vector<int> answer;
    
    string s = abc;
    while(true){
        cnt++;
        string str = erase1(s);
        s = BinaryChange(str);

        if(s.size()==1) break;
    }
    
    answer.push_back(cnt);
    answer.push_back(eraseCnt);
    return answer;
}