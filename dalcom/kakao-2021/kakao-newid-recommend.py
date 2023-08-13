possible = "qwertyuiopasdfghjklzxcvbnm1234567890-_."


def solution(new_id):
    answer = ""

    # step1
    new_id = new_id.lower()

    # step2
    tmp = ""
    for ch in new_id:
        if ch in possible:
            tmp += ch

    new_id = tmp

    # step3
    tmp = ""
    prev = new_id[0]
    for ch in new_id[1:]:
        if prev == "." and ch == ".":
            continue
        else:
            tmp += prev
        prev = ch
    tmp += prev
    new_id = tmp

    # step4
    new_id = new_id.strip(".")

    # step5
    new_id = "a" if new_id == "" else new_id

    # step6
    new_id = new_id[:15]
    if new_id[-1] == ".":
        new_id = new_id[:-1]

    # step7
    if len(new_id) <= 2:
        new_id = new_id + new_id[-1] * (3 - len(new_id))

    answer = new_id
    return answer
