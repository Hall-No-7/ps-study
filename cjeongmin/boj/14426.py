from sys import stdin
input = stdin.readline

class Node:
    def __init__(self, key: str | None):
        self.key = key
        self.is_word = False
        self.children: dict[str, Node] = {}


class Trie:
    def __init__(self):
        self.head = Node(key=None)

    def insert(self, word: str) -> None:
        curr = self.head
        for char in word:
            if char not in curr.children:
                curr.children[char] = Node(key=char)
            curr = curr.children[char]
        curr.is_word = True

    def search(self, word: str) -> bool:
        curr = self.head
        for char in word:
            if char not in curr.children:
                return False
            curr = curr.children[char]
        return curr.is_word

    def startsWith(self, prefix: str) -> bool:
        curr = self.head
        for char in prefix:
            if char not in curr.children:
                return False
            curr = curr.children[char]
        return True


N, M = map(int, input().split())
trie = Trie()
for _ in range(N):
    trie.insert(input().strip())

res = 0
for _ in range(M):
    if trie.startsWith(input().strip()):
        res += 1
print(res)
