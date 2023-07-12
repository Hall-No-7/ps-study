import sys

input = sys.stdin.readline


class Node:
    def __init__(self, key: str) -> None:
        self.key = key
        self.children: dict[str, Node] = {}
        self.visited = False


class Trie:
    def __init__(self) -> None:
        self.root = Node(key="")

    def insert(self, path: str) -> None:
        curr = self.root
        for dir in path.split("\\"):
            if dir not in curr.children:
                curr.children[dir] = Node(dir)
            curr = curr.children[dir]

    def traverse(self) -> None:
        stack: list[tuple[Node, int]] = [(self.root, 0)]
        self.root.visited = True
        while len(stack):
            curr, depth = stack[-1]
            for dir in sorted(curr.children.keys()):
                if curr.children[dir].visited:
                    continue
                stack.append((curr.children[dir], depth + 1))
                curr.children[dir].visited = True
                print(" " * depth, curr.children[dir].key, sep="")
                break
            else:
                stack.pop()


trie = Trie()
for _ in range(int(input())):
    trie.insert(input().strip())
trie.traverse()
