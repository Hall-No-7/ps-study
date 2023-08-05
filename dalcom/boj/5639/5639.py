from sys import stdin as input

input = open("/Volumes/Program/ps-study/dalcom/5639/input.txt", "rt")


class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


class Tree:
    def __init__(self, key):
        self.head = Node(key)

    def insert(self, key):
        cur = self.head
        parent = None
        while cur:
            parent = cur
            if cur.key > key:
                cur = cur.left
            else:
                cur = cur.right
        if parent.key > key:
            parent.left = Node(key)
        else:
            parent.right = Node(key)

    def postOrder(self):
        def recur(root):
            if root is None:
                return

            recur(root.left)
            recur(root.right)
            print(root.key)

        recur(self.head)


rootKey = input.readline()
tree = Tree(rootKey)

while True:
    try:
        key = input.readline()
        tree.insert(key)
    except:
        break

tree.postOrder()
