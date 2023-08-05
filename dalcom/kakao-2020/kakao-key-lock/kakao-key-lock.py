def expand(arr, isKey, sz, diff):
    result = [[0 if isKey else 1 for _ in range(sz)] for _ in range(sz)]

    for i in range(len(arr)):
        for j in range(len(arr)):
            result[i + diff][j + diff] = arr[i][j]
    return result


def rotate(key):
    result = [[[val for val in row] for row in key] for _ in range(4)]

    for r in range(1, 4):
        for i in range(len(key)):
            for j in range(len(key[i])):
                result[r][j][len(key) - i - 1] = result[r - 1][i][j]

    return result


def isUnlock(key, lock):
    tmp = [row[:] for row in lock]

    for i in range(len(lock)):
        for j in range(len(lock[0])):
            tmp[i][j] += key[i][j]
            if tmp[i][j] == 0 or tmp[i][j] > 1:
                return False
    return True


def moveKey(key, r, c):
    result = [[0 for _ in range(len(key))] for _ in range(len(key[0]))]

    for i in range(len(key)):
        for j in range(len(key[0])):
            rr = i + r
            cc = j + c
            if rr < 0 or rr >= len(key) or cc < 0 or cc >= len(key[0]):
                continue
            result[rr][cc] = key[i][j]

    return result


def solution(key, lock):
    if len(key) > len(lock):
        lock = expand(lock, False, len(key), (len(key) - len(lock)) // 2)
    elif len(key) < len(lock):
        key = expand(key, True, len(lock), (len(lock) - len(key)) // 2)

    for rkey in rotate(key):
        for i in range(-len(key) + 1, len(key)):
            for j in range(-len(key) + 1, len(key)):
                newKey = moveKey(rkey, i, j)

                if isUnlock(newKey, lock):
                    return True

    return False
