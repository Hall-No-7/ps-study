import re
from collections import defaultdict


class Node:
    def __init__(self):
        self.children: dict[str, Node] = {}
        self.lcnt = defaultdict(int)


class Trie:
    def __init__(self):
        self.head = Node()

    def insert(self, word):
        cur = self.head

        for i, ch in enumerate(word):
            if ch not in cur.children:
                cur.children[ch] = Node()
            cur.lcnt[len(word) - i] += 1
            cur = cur.children[ch]

    def search(self, query):
        cur = self.head

        for i, ch in enumerate(query):
            if ch == "?":
                return cur.lcnt[len(query) - i]
            if ch not in cur.children:
                return 0
            cur = cur.children[ch]

        return 0


def solution(words, queries):
    answer = []

    forward_trie = Trie()
    backward_trie = Trie()

    for word in words:
        forward_trie.insert(word)
        backward_trie.insert(word[::-1])

    for query in queries:
        if query[0] == "?":
            answer.append(backward_trie.search(query[::-1]))
        else:
            answer.append(forward_trie.search(query))

    return answer
