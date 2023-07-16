import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

class Root:
    val = 0
    def __init__(self, val):
        self.val = val

class Node:
    val = ''
    day = 0
    parentNode = None
    def __init__(self, val):
        self.val = val
        self.parentNode = None

def make_group(graph, visit, r, c):
    dr, dc = [0, 0, 1, -1], [1, -1, 0, 0]
    R, C = len(graph), len(graph[0])
    que = deque()
    que.append((r, c))
    visit[r][c] = True
    next_water_que = deque()
    while que:
        r, c = que.popleft()
        for i in range(4):
            nr, nc = r + dr[i], c + dc[i]
            if 0 <= nr < R and 0 <= nc < C and (visit[nr][nc] != True):
                if graph[nr][nc].val == '.':
                    visit[nr][nc] = True
                    graph[nr][nc].parentNode = graph[r][c].parentNode
                    que.append((nr, nc))
                elif graph[nr][nc].val == 'X':
                    # graph[nr][nc].day = graph[r][c].day + 1
                    next_water_que.append((r, c))
    return next_water_que

def solve(graph, visit, que):
    dr, dc = [0, 0, 1, -1], [1, -1, 0, 0]
    R, C = len(graph), len(graph[0])
    while que:
        r, c = que.popleft()
        for i in range(4):
            nr, nc = r + dr[i], c + dc[i]
            if 0 <= nr < R and 0 <= nc < C:
                if graph[nr][nc].parentNode == None:
                    graph[nr][nc].parentNode = graph[r][c].parentNode
                    visit[nr][nc] = True
                    graph[nr][nc].day = graph[r][c].day + 1
                    que.append((nr, nc))
                    continue
                if graph[nr][nc].parentNode.val < 2:
                    if graph[r][c].parentNode.val < 2:
                        if graph[nr][nc].parentNode.val != graph[r][c].parentNode.val:
                            graph[nr][nc].parentNode.val = graph[r][c].parentNode.val
                            return graph[nr][nc].day
                    else:
                        graph[r][c].parentNode.val = graph[nr][nc].parentNode.val
                else:
                    graph[nr][nc].parentNode.val = graph[r][c].parentNode.val
    return None

def main():
    R, C = map(int, input().split())
    visit = [[False for __ in range(C)] for _ in range(R)]
    lake = [list(map(Node, input())) for _ in range(R)]
    swanNum = 0
    waterNum = 2
    root = [Root(0), Root(1)] # 0: 백조1, 1: 백조2, 2 ... : 빙판 or 물
    water = deque()
    for r in range(R):
        for c in range(C):
            if lake[r][c].val == 'L':
                lake[r][c].val = '.'
                lake[r][c].parentNode = root[swanNum]
                next_water_que = make_group(lake, visit, r, c)
                while next_water_que:
                    water.append(next_water_que.popleft())
                swanNum += 1

    for r in range(R):
        for c in range(C):
            if visit[r][c] == False and lake[r][c].val == '.':
                root.append(Root(waterNum))
                lake[r][c].parentNode = root[waterNum]
                waterNum += 1
                next_water_que = make_group(lake, visit, r, c)
                while next_water_que:
                    water.append(next_water_que.popleft())
    print(solve(lake, visit, water))
main()


def printer(lake, R, C):
    for r in range(R):
        for c in range(C):
            if lake[r][c].parentNode == None:
                print(" ", end='')
            else:
                print(lake[r][c].parentNode.val, end='')
        print()
    print()