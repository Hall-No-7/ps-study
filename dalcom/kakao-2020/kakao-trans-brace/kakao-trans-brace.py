def isCorrectStr(word):
    st = []
    for ch in word:
        if ch == "(":
            st.append(ch)
        elif ch == ")" and len(st):
            st.pop()
        else:
            return False
    return True


def divideStr(word):
    result = ""
    for idx, ch in enumerate(word):
        result += ch
        if result.count("(") == result.count(")"):
            return result, word[idx + 1 :]
    return word, ""


def reverseStr(w):
    result = ""
    for ch in w:
        if ch == "(":
            result += ")"
        else:
            result += "("

    return result


def recur(w):
    if w == "":
        return w

    u, v = divideStr(w)

    if isCorrectStr(u):
        v = recur(v)
        return u + v
    else:
        v = recur(v)
        u = reverseStr(u[1:-1])
        return "(" + v + ")" + u


def solution(p):
    answer = ""

    if isCorrectStr(p):
        return p

    answer = recur(p)

    return answer
