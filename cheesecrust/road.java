import java.util.*;


class Solution {
    
    static int[][] answer = {};
    static int idx = 0;
    
    public int[][] solution(int[][] nodeinfo) {
   
        answer = new int[2][nodeinfo.length];
        List<Node> nodeList = new ArrayList<>();
        
        int num = 1;
        for(int[] node : nodeinfo){
            nodeList.add(new Node(num++, node[0], node[1], null, null));
        }
        
        nodeList.sort((o1,o2) -> o1.x - o2.x);
        nodeList.sort((o1,o2) -> o2.y - o1.y);
        
        Node root = nodeList.get(0);        
        
//         for(Node node : nodeList){
//             System.out.println(node.num);
//         }
        
        for(int i = 1; i < nodeList.size(); i++){
            insertNode(root, nodeList.get(i));
        }
        
        idx = 0;
        preOrder(root);
        idx = 0;
        postOrder(root);
        
        return answer;
    }


    static class Node {
        int num = 0;
        int x = 0;
        int y = 0;
        Node left = null;
        Node right = null;
    
        Node(int num, int x, int y, Node left, Node right){
            this.num = num;
            this.x = x;
            this.y = y;
            this.left = left;
            this.right = right;
        }
    }

    static void insertNode(Node parent, Node child){
        if(parent.x > child.x){
            if(parent.left == null){
                parent.left = child;
            }else{
                insertNode(parent.left, child);
            }
        }else {
            if(parent.right == null){
                parent.right = child;
            }else{
                insertNode(parent.right, child);
            }
        }
        
        return;
    }
    
    static void preOrder(Node root){
        if(root != null){
            answer[0][idx++] = root.num;
            preOrder(root.left);
            preOrder(root.right);
        }
    }
    
    static void postOrder(Node root){
        if(root != null){
            postOrder(root.left);
            postOrder(root.right);
            answer[1][idx++] = root.num;
        }
    }
    
}
