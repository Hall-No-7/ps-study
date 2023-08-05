from sys import stdin as input

input = open("/Volumes/Program/ps-study/dalcom/14426/input.txt", "rt")

n, m = map(int, input.readline().split())


class Node:
    def __init__(self, key: str) -> None:
        self.key = key
        self.children: dict[str, Node] = {}
        self.isWord = False


class Trie:
    def __init__(self) -> None:
        self.head = Node(None)

    def insert(self, word: str):
        cur = self.head
        for char in word:
            if char not in cur.children:
                cur.children[char] = Node(char)
            cur = cur.children[char]
        cur.isWord = True

    def search(self, word: str) -> bool:
        cur = self.head
        for char in word:
            if char not in cur.children:
                return False
            cur = cur.children[char]
        return True


result = 0
trie = Trie()

for _ in range(n):
    trie.insert(input.readline().strip())

for _ in range(m):
    result += 1 if trie.search(input.readline().strip()) else 0

print(result)
