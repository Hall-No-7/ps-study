from sys import stdin as input

input = open("/Volumes/Program/ps-study/dalcom/14725/input.txt", "rt")


class Node:
    def __init__(self, key: str) -> None:
        self.key = key
        self.children: dict[str, Node] = {}


class Trie:
    def __init__(self) -> None:
        self.head = Node(None)

    def insert(self, words: list):
        cur = self.head
        for word in words:
            if word not in cur.children:
                cur.children[word] = Node(word)
            cur = cur.children[word]

    def search(self):
        cur = self.head

        def recur(depth, node: Node):
            if len(node.children) == 0:
                return
            for key, value in sorted(node.children.items()):
                print("--" * depth, end="")
                print(key)
                recur(depth + 1, value)

        recur(0, cur)


n = int(input.readline())

trie = Trie()
for _ in range(n):
    _, *foods = list(map(str, input.readline().split()))
    trie.insert(foods)
trie.search()
