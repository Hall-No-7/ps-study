import sys

sys.setrecursionlimit(10**6)


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Node:
    def __init__(self, key, pos):
        self.key = key
        self.pos = pos
        self.left = None
        self.right = None


class Tree:
    def __init__(self, key, pos):
        self.head = Node(key, pos)

    def insert(self, key, pos):
        parent = self.head
        cur = self.head
        while cur is not None:
            parent = cur
            if cur.pos.x > pos.x:
                cur = cur.left
            else:
                cur = cur.right
        if parent.pos.x > pos.x:
            parent.left = Node(key, pos)
        else:
            parent.right = Node(key, pos)

    def preorder(self, result):
        def recur(root):
            if root is None:
                return
            result.append(root.key)
            recur(root.left)
            recur(root.right)

        recur(self.head)

    def postorder(self, result):
        def recur(root):
            if root is None:
                return
            recur(root.left)
            recur(root.right)
            result.append(root.key)

        recur(self.head)


def solution(nodeinfo):
    answer = []

    data = []
    for idx, info in enumerate(nodeinfo, 1):
        data.append((idx, Point(info[0], info[1])))

    data = sorted(data, key=lambda x: x[1].y, reverse=True)

    tree = Tree(data[0][0], data[0][1])

    for key, pos in data[1:]:
        tree.insert(key, pos)

    pre_result = []
    post_result = []
    tree.preorder(pre_result)
    tree.postorder(post_result)

    answer.append(pre_result)
    answer.append(post_result)

    return answer
