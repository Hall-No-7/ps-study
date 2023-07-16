import sys

sys.setrecursionlimit(10**9)
input = lambda: sys.stdin.readline().rstrip()

def find(gates, g):
    if gates[g] != g:
        gates[g] = find(gates, gates[g])
    return gates[g]

def docking(gates, gx):
    root = find(gates, gx)
    gates[root] = root - 1
    if root < 1:
        return False
    return True

def main():
    G = int(input())
    gates = [ i for i in range(G + 1)]
    P = int(input())
    answer = 0 
    lis = []
    for _ in range(P):
        lis.append(int(input()))
    for g in lis:
        flag = docking(gates, g)
        # print(g, gates)
        if flag:
            answer += 1
        else:
            break
        
    
    print(answer)
main()