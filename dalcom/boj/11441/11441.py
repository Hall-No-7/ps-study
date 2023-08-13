from sys import stdin as input

input = open("/Volumes/Program/ps-study/dalcom/boj/11441/input.txt", "rt")

n = int(input.readline())

arr = []
sum = [0 for _ in range(n + 1)]

arr = list(map(int, input.readline().split()))

sum[0] = arr[0]

for i in range(1, n):
    sum[i] = sum[i - 1] + arr[i]

m = int(input.readline())

for _ in range(m):
    i, j = map(int, input.readline().split())
    print(sum[j - 1] - sum[i - 2])
