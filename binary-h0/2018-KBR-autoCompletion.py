import sys
sys.setrecursionlimit(10**9)
class TrieNode:
    isEnd = False
    childs = {}
    
    def __init__(self):
        self.isEnd = False
        self.childs = {}

def insert(root, lis, idx):
    if len(lis) == idx:
        root.isEnd = True
        return
    if lis[idx] not in root.childs.keys():
        root.childs[lis[idx]] = TrieNode()
        return insert(root.childs[lis[idx]], lis, idx + 1)
    return insert(root.childs[lis[idx]], lis, idx + 1)
        
def dfs(root, word, depth, count):
    if len(word) == depth:
        if len(root.childs) != 0:
            return depth
        return count
    
    if (len(root.childs) == 0):
        return count
    elif (len(root.childs) == 1):
        if root.isEnd:
            count = depth + 1
    else:
        count = depth + 1
    
    
    return dfs(root.childs[word[depth]], word, depth + 1, count)
    
    

def solution(words):
    answer = 0
    trie = TrieNode()

    for word in words:
        insert(trie, word, 0)
        
    for word in words:
        answer += dfs(trie.childs[word[0]], word, 1, 1)
    
    return answer