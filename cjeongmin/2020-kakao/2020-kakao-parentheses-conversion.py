def conversion(w):
    if w == "":
        return ""
    
    idx = split(w)
    u, v = w[:idx + 1], w[idx + 1:]
    if check(u):
        return u + conversion(v)
    else:
        temp = "(" + conversion(v) + ")"
        u = "".join((list(map(lambda x: "(" if x == ")" else ")", u[1:-1]))))
        return temp + u


def split(p):
    idx = 0
    cnt = { "(": 0, ")": 0 }
    for c in p:
        cnt[c] += 1
        if cnt["("] == cnt[")"]:
            break
        idx += 1
    return idx


def check(p):
    stk = []
    for c in p:
        if c == "(":
            stk.append(c)
        elif len(stk) > 0 and c == ")":
            stk.pop()
        else:
            return False
    if len(stk):
        return False
    return True


def solution(p):
    return conversion(p)
