#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> apeach_info;
vector<int> ret_info;
int ret;


bool compare(vector<int> v){
    
    
    for(int i=10; i>=0; i--){
            if(ret_info[i] < v[i]) return true;
            else if(ret_info[i] == v[i]) continue;
            else return false;
    }
        return false;
}


void go(int pos,int num,vector<int> rion_info){
    if( (num==0) || (pos>10)) {
        
        if(num>0) rion_info[10]+=num;
        
        int sum_rion = 0;
        int sum_apeach=0;
        
         for(int i=0; i<rion_info.size(); i++){
            if(rion_info[i]==0 && apeach_info[i]==0) continue;
            if(rion_info[i]>apeach_info[i]) sum_rion+=10-i;
            else sum_apeach+=10-i;
        }
        
        int s_sum = sum_rion-sum_apeach;
        
        if( sum_rion > sum_apeach && ret==(s_sum) && compare(rion_info) ) {
            ret=s_sum;
            ret_info = rion_info;
        }
        
        else if(sum_rion > sum_apeach && s_sum > ret){
            ret = s_sum;
            ret_info = rion_info;
        }
       //  cout<<"sum_rion : "<<sum_rion << " sum_apeach :"<<sum_apeach<<" ret : "<<ret <<'\n'; 
        return;
    }
    
    
    go(pos+1,num,rion_info); // case 1
    
    if(num >= apeach_info[pos]+1) { 
        rion_info[pos] = apeach_info[pos] + 1;
        go(pos+1,num-apeach_info[pos]-1,rion_info); //case 2
    }
    
    return;
                                
}


vector<int> solution(int n, vector<int> info) {
    apeach_info = info;
    
    
    
    vector<int> v;
    for(int i=0; i<11; i++){
        v.push_back(0);
    }
    go(0,n,v);
    
    
    
    vector<int> fail_v;
    fail_v.push_back(-1);
    if(ret==0) return fail_v;
    
    return ret_info;
}