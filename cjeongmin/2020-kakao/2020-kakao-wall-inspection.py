from itertools import permutations


def solution(n, weak, dist):
    answer = len(dist) + 1
    
    for sequence in permutations(dist, len(dist)):
        m = len(weak)
        for start in range(m):
            i = 0
            for index, curr in enumerate(sequence, 1):
                x = weak[(start + i) % m]
                
                while (
                    i + 1 < m
                    and (
                        x <= weak[(start + i + 1) % m] <= min(x + curr, n - 1)
                        or (x + curr >= n and 0 <= weak[(start + i + 1) % m] <= (x + curr) % n)
                    )
                ):
                    i += 1
                i += 1
                
                if i == m:
                    if answer > index:
                        answer = index
                        break
    
    return answer if answer <= len(dist) else -1
