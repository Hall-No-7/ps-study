from sys import stdin

input = stdin.readline


class Node:
    def __init__(self, key: str | None):
        self.key = key
        self.count = 0
        self.children: dict[str, Node] = {}


class Trie:
    def __init__(self):
        self.head = Node(key=None)

    def insert(self, word: str) -> None:
        alias = ""
        setAlias = False

        curr = self.head
        for char in word:
            alias += char
            if char not in curr.children:
                curr.children[char] = Node(key=char)
                if not setAlias:
                    print(alias)
                    setAlias = True
            curr = curr.children[char]
        curr.count += 1
        if not setAlias:
            print(alias + (str(curr.count) if curr.count > 1 else ""))

    def search(self, word: str) -> bool:
        curr = self.head
        for char in word:
            if char not in curr.children:
                return False
            curr = curr.children[char]
        return curr.count > 0

    def startsWith(self, prefix: str) -> bool:
        curr = self.head
        for char in prefix:
            if char not in curr.children:
                return False
            curr = curr.children[char]
        return True


trie = Trie()
for _ in range(int(input())):
    nickname = input().strip()
    trie.insert(nickname)
