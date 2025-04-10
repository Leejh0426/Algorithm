#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int arr[60004];

int solution(int n) {
    arr[0]=1;
    arr[1]=1;
   for(int i=2; i<=n; i++){
       arr[i]=(arr[i-1]+arr[i-2])%1000000007;
   }
    return arr[n];
}