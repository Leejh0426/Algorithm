#include<bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

bool arr[10004];
bool reversearr[10004];

int sortt[1000003];
int reversesortt[1000004];


void go(vector<int> &topping){
    int sort1=0;
    int reversesort1=0;
    for(int i=0;i<topping.size();i++){
        if(!arr[topping[i]]){
            sortt[i]=++sort1;
            arr[topping[i]]=true;
        }
        else{
            sortt[i]=sort1;
        }
        //cout<<"sortt[i]: "<<sortt[i]<<'\n';
    }
    
    for(int i=topping.size()-1;i>=0;i--){
        if(!reversearr[topping[i]]){
            reversesortt[i]=++reversesort1;
            reversearr[topping[i]]=true;
        }
        else{
            reversesortt[i]=reversesort1;
        }
    } 
    return;
}


int solution(vector<int> topping) {
    int answer = 0;
    
    go(topping);

    for(int i=0; i<topping.size()-1;i++){
       // cout<<sortt[i]<<" "<<reversesortt[i+1]<<'\n';
        if(sortt[i]==reversesortt[i+1]) answer++;
    } 

    
    return answer;
}