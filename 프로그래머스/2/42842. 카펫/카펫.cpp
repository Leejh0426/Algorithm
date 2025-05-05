#include <string>
#include <vector>

using namespace std;


    

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum = brown+yellow;
    for(int i=1;i<=sum/2;i++){
        if(sum%i) continue;
        if( ( (sum/i*2) + (2*i-4)) == brown){
            answer.push_back(sum/i);
            answer.push_back(i);
            break;
        }
        
    }
    
    return answer;
}