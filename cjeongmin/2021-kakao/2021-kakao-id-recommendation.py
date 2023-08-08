import re


def solution(new_id):
    new_id = new_id.lower()
    new_id = list(filter(lambda c: c not in "~!@#$%^&*()=+[{]}:?,<>/", new_id))
    new_id = "".join(new_id)
    new_id = re.sub("[.]+", ".", new_id)
    new_id = new_id.strip(".")
    if len(new_id) == 0:
        new_id = "a"
    elif len(new_id) >= 16:
        new_id = new_id[:15]
        new_id = new_id.rstrip(".")
    if len(new_id) <= 2:
        new_id = new_id + new_id[-1] * (3 - len(new_id))
    return new_id
