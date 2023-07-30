import sys
sys.setrecursionlimit(10**8)
def split(s):
    l ,r = 0, 0
    stack = []
    flag = True
    u, v = "", ""
    for c in s:
        stack.append(c)
        if c == "(":
            l += 1
        else:
            r += 1
        if (l == r) and flag:
            u = "".join(stack)
            stack = []
            flag = False
    v = "".join(stack)
    return (u, v)

def is_good(s):
    stack = []
    for c in s:
        if c == "(":
            stack.append(c)
        else:
            if len(stack) == 0:
                return False
            else:
                stack.pop()
    return True

def reverse(s):
    if len(s) == 0:
        return s
    else:
        stack = []
        for i in range(1, len(s) -1):
            if s[i] == "(":
                stack.append(")")
            else:
                stack.append("(")
        return "".join(stack)

def solve(s):
    if len(s) == 0:
        return ""
    u, v = split(s)
    if is_good(u):
        return u + solve(v)
    else:
        return "(" + solve(v) + ")" + reverse(u)

def solution(p):
    answer = ""
    # print(split(p))
    answer = solve(p)
    return answer