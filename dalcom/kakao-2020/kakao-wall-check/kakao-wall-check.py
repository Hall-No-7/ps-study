"""
해설 보고 풀었음
"""


def solution(n, weak, dist):
    answer = 0
    result = [()]

    for d in sorted(dist, reverse=True):
        answer += 1
        cp_lst = []
        for i, p in enumerate(weak):
            start = p
            ends = weak[i:] + [n + w for w in weak[:i]]  # 원형을 1차원으로

            possible = []
            for end in ends:
                if (end - start) <= d:
                    possible.append(end % n)

            cp_lst.append(set(possible))

        union = set()
        for cp in cp_lst:
            for rp in result:
                new = cp | set(rp)
                if len(new) == len(weak):
                    return answer
                union.add(tuple(new))

        result = union

    return -1
