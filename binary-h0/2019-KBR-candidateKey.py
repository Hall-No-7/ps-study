from itertools import combinations
from collections import deque


def make_tuple_lis(c_lis, rel):
    tmp_set = set()
    C = len(rel)
    for tup in rel:
        lis = []
        for target in c_lis:
            lis.append(tup[target])
        s = ''.join(lis)
        tmp_set.add(s)
    # print(tmp_set)
    return tmp_set
    

def solution(relation):
    answer = 0
    R = len(relation)
    C = len(relation[0])
    que = deque()
    for i in range(C): que.append([i])
    comb_lis = []
    success_lis = []
    for c in range(1, C + 1):
        for comb in combinations(range(C), c):
            comb_lis.append(set(comb))
    
    for c_lis in comb_lis:
        for s_set in success_lis:
            if len(s_set) == len(s_set & c_lis):
                break
        else:
            tmp_set = make_tuple_lis(c_lis, relation)
            # print("SET:", tmp_set)
            if R == len(tmp_set):
                answer += 1
                success_lis.append(c_lis)
    
    return answer
