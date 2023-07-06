import sys
input = sys.stdin.readline

class TrieNode:
    children = {}
    end = False

    def __init__(self):
        self.children = {}
        self.end = False

def insert(_trie, lis, idx):
    if idx == len(lis):
        _trie.end = True
        return
    if lis[idx] not in _trie.children:
        _trie.children[lis[idx]] = TrieNode()
    insert(_trie.children[lis[idx]], lis, idx+1)

def print_trie(trie, depth):
    if trie.end:
        return
    for key in sorted(trie.children.keys()):
        print('--'*depth + key)
        print_trie(trie.children[key], depth + 1)

def main():
    N = int(input().rstrip())
    trie = TrieNode()
    trie.end = False
    for _ in range(N):
        line = list(input().rstrip().split())
        insert(trie, line[1:], 0)
    print_trie(trie, 0)
main()