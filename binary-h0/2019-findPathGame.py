import sys
sys.setrecursionlimit(10**9)
class Node:
    def __init__(self, info : list):
        self.x = info[0]
        self.y = info[1]
        self.val = info[2]
        self.l = None
        self.r = None

class Tree:
    def __init__(self):
        self.node = None
    
    def append(self, _node : Node):
        if self.node == None:
            self.node = _node
            return
        root = self.node
        while root != None:
            if _node.x < root.x:
                if root.l == None:
                    root.l = _node
                    break
                root = root.l
            else:
                if root.r == None:
                    root.r = _node
                    break
                root = root.r
        
def preorder(root : Node, lis : list):
    if root == None:
        return
    lis.append(root.val)
    preorder(root.l, lis)
    preorder(root.r, lis)
        
    
def postorder(root : Node, lis : list):
    if root == None:
        return
    postorder(root.l, lis)
    postorder(root.r, lis)
    lis.append(root.val)

def solution(nodeinfo):
    answer = []
    for i in range(len(nodeinfo)): nodeinfo[i].append(i + 1)
    nodeinfo.sort(key=lambda x: x[0])
    nodeinfo.sort(reverse=True, key=lambda x: x[1])
    tree = Tree()
    for node in nodeinfo:
        _node = Node(node)
        tree.append(_node)
    lis = []
    preorder(tree.node, lis)
    answer.append(lis)
    lis = []
    postorder(tree.node, lis)
    answer.append(lis)
    
    
    
    return answer