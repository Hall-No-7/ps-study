def rotate(A):
    ret = [[0] * len(A) for _ in range(len(A))]
    for r in range(len(A)):
        for c in range(len(A)):
            ret[c][len(A) - 1 - r] = A[r][c]
    return ret
    

def unlock(key, lock):
    N = len(lock)
    M = len(key)
    lock = resize(lock, N + (M - 1) * 2, N, M)
    for _ in range(4):
        for r in range(len(lock) - M + 1):
            for c in range(len(lock) - M + 1):
                for y in range(M):
                    for x in range(M):
                        lock[r + y][c + x] += key[y][x]
                
                if check(lock, N, M):
                    return True
                
                for y in range(M):
                    for x in range(M):
                        lock[r + y][c + x] -= key[y][x]
        key = rotate(key)
    return False
    
    
def check(lock, N, M):
    offset = M - 1
    for r in range(N):
        for c in range(N):
            if lock[offset + r][offset + c] != 1:
                return False
    return True


def resize(A, size, N, M):
    offset = M - 1
    ret = [[0] * size for _ in range(size)]
    for r in range(N):
        for c in range(N):
            ret[offset + r][offset + c] = A[r][c]
    return ret


def solution(key, lock):
    return unlock(key, lock)
