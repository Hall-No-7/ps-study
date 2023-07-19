from itertools import combinations, compress


def issubset(A, B):
    for element in B:
        if element.issubset(A):
            return True
    return False


def solution(relation):
    answer = 0
    
    passed = []
    base = [i for i in range(1, len(relation[0]) + 1)]
    for length in range(1, len(base) + 1):
        for indexes in combinations(base, length):
            if issubset(set(indexes), passed):
                continue
            
            selector = [0 for _ in range(len(base))]
            for idx in indexes:
                selector[idx - 1] = 1

            res = {}
            for row in relation:
                row = tuple(compress(row, selector))
                if row not in res:
                    res[row] = True
                else:
                    break
            else:
                passed.append(set(indexes))
                answer += 1
                
    return answer
