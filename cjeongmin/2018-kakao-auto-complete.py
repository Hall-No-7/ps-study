class Node:
    def __init__(self):
        self.children = {}
        self.cnt = 0
        self.isWord = False
        

class Trie:
    def __init__(self):
        self.root = Node()
        
    def insert(self, word):
        curr = self.root
        curr.cnt += 1
        for c in word:
            if c not in curr.children:
                curr.children[c] = Node()
            curr = curr.children[c]
            curr.cnt += 1
        self.isWord = True
        
    def calculateCharacterCount(self, word):
        cnt = 0
        curr = self.root
        for c in word:
            cnt += 1
            curr = curr.children[c]
            if curr.cnt == 1:
                break
        return cnt
    
    
def solution(words):
    answer = 0
    trie = Trie()
    for word in words:
        trie.insert(word)
    
    for word in words:
        answer += trie.calculateCharacterCount(word)
    return answer
