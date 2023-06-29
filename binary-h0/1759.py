import sys
input = sys.stdin.readline

def main():
    def dfs(idx, cnt, mo, ja):
        if cnt == L:
            if mo >= 1 and ja >= 2:
                print(''.join(map(str, result)))
            return
        for i in range(idx, C):
            result.append(arr[i])
            if arr[i] in ['a', 'e', 'i', 'o', 'u']:
                dfs(i+1, cnt+1, mo+1, ja)
            else:
                dfs(i+1, cnt+1, mo, ja+1)
            result.pop()

    L, C = map(int, input().rstrip().split())
    arr = list(input().rstrip().split())
    arr.sort()
    result = []
    dfs(0, 0, 0, 0)

main()