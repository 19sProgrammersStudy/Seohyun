// Level 2. 타겟 넘버
// https://programmers.co.kr/learn/courses/30/lessons/43165?language=cpp

#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define MAX 20
int pos[MAX] = {0, };
int neg[MAX] = {0, };

int targetNum, len, answer;

void calculate(int cur, int idx) {
    if(idx == len) {
        if(cur == targetNum) answer++;
        return;
    }
    
    calculate(cur + pos[idx], idx+1);
    calculate(cur + neg[idx], idx+1);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    targetNum = target;
    len = numbers.size();
    
    // 1. 양수/음수 각각 초기화
    for(int idx=0; idx<len; idx++) {
        pos[idx] = numbers[idx];
        neg[idx] = numbers[idx] * -1;
    }
    
    // 2. 경우의 수에 따라서 분기시키기
    calculate(pos[0], 1);
    calculate(neg[0], 1);
    
    return answer;
}