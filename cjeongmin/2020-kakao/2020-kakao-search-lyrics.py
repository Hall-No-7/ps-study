from collections import defaultdict


class Node:
    def __init__(self):
        self.children = {}
        self.count = defaultdict(int)


class Trie:
    def __init__(self):
        self.root = Node()
        
    def insert(self, word):
        curr = self.root
        for i, c in enumerate(word):
            if c not in curr.children:
                curr.children[c] = Node()
            curr.count[len(word) - i] += 1
            curr = curr.children[c]
            
    def countPrefixMatch(self, prefix):
        curr = self.root
        for i, c in enumerate(prefix):
            if c == "?":
                return curr.count[len(prefix) - i]
            if c not in curr.children:
                return 0
            curr = curr.children[c]
        return 0
        

def solution(words, queries):
    answer = []
    
    trie = Trie()
    reverse = Trie()
    for word in words:
        trie.insert(word)
        reverse.insert(word[::-1])
        
    for query in queries:
        if query[-1] == "?":
            answer.append(trie.countPrefixMatch(query))
        else:
            answer.append(reverse.countPrefixMatch(query[::-1]))
    
    return answer
