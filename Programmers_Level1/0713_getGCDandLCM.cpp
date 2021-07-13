// Level 1. 최대공약수와 최소공배수
// 

#include <string>
#include <vector>

using namespace std;

bool isGCD(int n, int m, int div) {
    if(n % div == 0 && m % div == 0)
        return true;
    else
        return false;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    if(n >= m) {
        for(int idx=m; idx>=1; idx--) {
            if(isGCD(n, m, idx)) {
                answer.push_back(idx);
                break;
            }
        }
    }
    else {
        for(int idx=n; idx>=1; idx--) {
            if(isGCD(n, m, idx)) {
                answer.push_back(idx);
                break;
            }
        }
    }
    
    answer.push_back((n*m)/answer[0]);
    return answer;
}