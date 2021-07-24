# Level 2. 최댓값과 최솟값
# https://programmers.co.kr/learn/courses/30/lessons/12939?language=python3

def solution(s):
    nums = list(map(int, s.split(' ')))
    answer = str(min(nums)) + ' ' + str(max(nums))
    return answer