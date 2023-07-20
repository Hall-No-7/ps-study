import sys
from heapq import *

input = lambda: sys.stdin.readline().rstrip()

def solve(graph, blank_lis, r_lis, c_lis, b_lis, depth):
    if depth == len(blank_lis):
        return True
    r, c = blank_lis[depth]
    for num in range(1, 10):
        if num in r_lis[r]:
            continue
        if num in c_lis[c]:
            continue
        if num in b_lis[(3 * (r//3)) + (c // 3)]:
            continue
        r_lis[r].add(num)
        c_lis[c].add(num)
        b_lis[(3 * (r//3)) + (c // 3)].add(num)
        if solve(graph, blank_lis, r_lis, c_lis, b_lis, depth + 1):
            graph[r][c] = num
            return True
        r_lis[r].remove(num)
        c_lis[c].remove(num)
        b_lis[(3 * (r//3)) + (c // 3)].remove(num)
    return False
        

def main():
    blank_lis = []
    blocks = [set() for _ in range(9)]
    able_r_lis = []
    able_c_lis = [set() for _ in range(9)]
    graph = []
    for r in range(9):
        items = list(map(int, input().split()))
        able_r_lis.append(set(items))
        graph.append(items)
        for c in range(9):
            item = items[c]
            able_c_lis[c].add(item)
            blocks[(3 * (r//3)) + (c // 3)].add(item)
            if item == 0:
                blank_lis.append((r, c))

    solve(graph, blank_lis, able_r_lis, able_c_lis, blocks, 0)
    for i in graph:
        print(*i)

main()