#include <string>
#include <vector>

using namespace std;

int arr[100004];

int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(arr[n]) return arr[n];
    arr[n] = (fib(n-1)%1234567 + fib(n-2)%1234567)%1234567;
    return arr[n];
}

int solution(int n) {
    return fib(n);
}