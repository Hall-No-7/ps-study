def compress(w, l):
    result = ""
    prev = w[0:l]
    cnt = 1

    for i in range(l, len(w), l):
        cur = w[i : i + l]
        if prev == cur:
            cnt += 1
        else:
            wcnt = str(cnt) if cnt != 1 else ""
            result += wcnt + prev
            cnt = 1
        prev = cur

    wcnt = str(cnt) if cnt != 1 else ""
    result += wcnt + prev

    return len(result)


def solution(s):
    answer = 1000

    for i in range(1, len(s) // 2 + 2):
        answer = min(compress(s, i), answer)

    return answer
