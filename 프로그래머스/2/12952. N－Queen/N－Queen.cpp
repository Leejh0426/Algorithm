#include <string>
#include <vector>

using namespace std;

int ret=0;
bool check[12][12];

bool checking(int y, int x,int n){
    
    for(int i=0; i<n;i++){
        if(check[i][x]) return true;
    }

    for(int i=0;i<n;i++){
        if(y+i >=0 && y+i<n && x+i>=0 && x+i<n && check[y+i][x+i]) return true;
        if(y+i >=0 && y+i<n && x-i>=0 && x-i<n && check[y+i][x-i]) return true;
        if(y-i >=0 && y-i<n && x+i>=0 && x+i<n&&check[y-i][x+i]) return true;
        if(y-i >=0 && y-i<n && x-i>=0 && x-i<n&& check[y-i][x-i])return true;
    }
    
    return false;
}

void go(int y,int n){
    if(y==n){ 
        ret++;
        return;
    }

    for(int j=0; j<n;j++){
        if(check[y][j]) continue;
        if(checking(y,j,n))continue;
        check[y][j]=true;
        go(y+1,n);
        check[y][j]=false;
    }
    return;
}

int solution(int n) {
    go(0,n);
    return ret;
}

