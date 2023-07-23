import sys
from copy import deepcopy
import asyncio
import time

input = lambda: sys.stdin.readline().rstrip()

def main():
    R, C = map(int, input().split())
    graph = [list(input()) for _ in range(R)]
    dr, dc = [-1, 0, 1, 0], [0, 1, 0, -1]
    coins = []
    for r in range(R):
        for c in range(C):
            if graph[r][c] == 'o':
                coins.append((r, c))

    async def solve(_graph, _coins, depth):
        for r, c in _coins:
            for i in range(4):
                nr, nc = r + dr[i], c + dc[i]



    # asyncio.run(solve(deepcopy(graph), deepcopy(coins), 0))

    async def time_sleep():
        await asyncio.sleep(1)

    async def lis():
        t = time.time()
        await asyncio.gather(
            time_sleep(),
            time_sleep(),
            time_sleep(),
            time_sleep()
                       )
        print(time.time() - t)
    asyncio.run(lis())
main()