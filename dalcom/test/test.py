from bisect import bisect_left, bisect_right


class Node:
    def __init__(self, key):
        self.key = key
        self.children = dict()


class Tree:
    def __init__(self):
        self.head = Node(None)
        lang = ["java", "cpp", "python", "-"]
        pos = ["backend", "frontend", "-"]
        car = ["junior", "senior", "-"]
        food = ["chicken", "pizza", "-"]
        keys = [lang, pos, car, food]

        cur = self.head

        def recur(root, key_idx):
            if key_idx == 4:
                return

            for key in keys[key_idx]:
                new_node = Node(key)
                root.children[key] = new_node
                recur(root.children[key], key_idx + 1)

        recur(cur, 0)

    def insert(self, info):
        lang, pos, car, food, score = info.split()
        keys = [lang, pos, car, food]
        score = int(score)

        cur = self.head

        def recur(root, key_idx):
            if key_idx == 4:
                if len(root.children) == 0:
                    root.children = [float("INF"), score]
                else:
                    root.children += [score]
                return

            recur(root.children[keys[key_idx]], key_idx + 1)
            recur(root.children["-"], key_idx + 1)

        recur(cur, 0)

    def search(self, query):
        q_lst = query.split()
        q_lst = [x for x in q_lst if x != "and"]
        lang, pos, car, food, score = q_lst
        keys = [lang, pos, car, food]

        cur = self.head

        def recur(root, key_idx):
            if key_idx == 4:
                if root.children[0] == float("inf"):
                    root.children.sort()
                    root.children.pop()
                cnt = len(root.children) - bisect_left(root.children, int(score))
                return cnt

            try:
                answer = recur(root.children[keys[key_idx]], key_idx + 1)
            except:
                print("hi")
            return answer

        answer = recur(cur, 0)
        return answer


def solution(info, query):
    answer = []

    tree = Tree()

    for i in info:
        tree.insert(i)

    for q in query:
        answer.append(tree.search(q))

    return answer


solution(
    [
        "java backend junior pizza 150",
        "python frontend senior chicken 210",
        "python frontend senior chicken 150",
        "cpp backend senior pizza 260",
        "java backend junior chicken 80",
        "python backend senior chicken 50",
    ],
    [
        "java and backend and junior and pizza 100",
        "python and frontend and senior and chicken 200",
        "cpp and - and senior and pizza 250",
        "- and backend and senior and - 150",
        "- and - and - and chicken 100",
        "- and - and - and - 150",
    ],
)
