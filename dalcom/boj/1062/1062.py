from sys import stdin as input
from itertools import combinations

input = open("/Volumes/Program/ps-study/dalcom/1062/input.txt", "rt")


def convert(word):
    bit = 0
    for char in word:
        bit = bit | (1 << ord(char) - ord("a"))
    return bit


n, k = map(int, input.readline().split())
words = [set(input.readline().rstrip()) for _ in range(n)]
bits = list(map(convert, words))
essential = convert("antic")

if k < 5:
    print(0)
else:
    alphabet = [1 << i for i in range(26) if not (essential & 1 << i)]
    answer = 0
    for combination in combinations(alphabet, k - 5):
        learn = sum(combination) | essential
        cnt = 0
        for bit in bits:
            if bit & learn == bit:
                cnt += 1
        answer = max(answer, cnt)
    print(answer)
