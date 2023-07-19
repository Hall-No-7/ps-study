from sys import setrecursionlimit

class Node:
    def __init__(self, key, x, y):
        self.key = key
        self.x = x
        self.y = y
        self.left = None
        self.right = None
        

class Tree:
    def __init__(self):
        self.root = None
    
    def insert(self, key, x, y):
        def _insert(curr, key, x, y):
            if curr is None:
                return Node(key, x, y)
            
            if x < curr.x:
                curr.left = _insert(curr.left, key, x, y)
            elif x > curr.x:
                curr.right = _insert(curr.right, key, x, y)
            return curr
        
        
        self.root = _insert(self.root, key, x, y)
        
    def preorder(self):
        def _preorder(curr):
            nonlocal res
            if curr is None:
                return

            res.append(curr.key)
            _preorder(curr.left)
            _preorder(curr.right)
            
        res = []
        _preorder(self.root)
        return res
    
    def postorder(self):
        def _postorder(curr):
            nonlocal res
            if curr is None:
                return
            
            _postorder(curr.left)
            _postorder(curr.right)
            res.append(curr.key)
        
        res = []
        _postorder(self.root)
        return res
            

def solution(nodeinfo):
    setrecursionlimit(int(10e6))
    nodeinfo = list(enumerate(nodeinfo))
    nodeinfo.sort(key=lambda x: (-x[1][1], x[1][0]))
    tree = Tree()
    for node in nodeinfo:
        tree.insert(node[0] + 1, node[1][0], node[1][1])
    return [tree.preorder(), tree.postorder()]
