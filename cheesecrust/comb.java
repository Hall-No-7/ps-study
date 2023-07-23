import java.util.*;

class Solution {
    static int n,m;
    static List<HashSet<Integer>> candidateKey;
    static String[][] relationCopy;
    static int answer;
    public int solution(String[][] relation) {
        answer = 0;
        
        relationCopy = relation;
        candidateKey = new ArrayList<>();
        n = relation.length;
        m = relation[0].length;
        
        for(int i = 1; i <= m; i++){
            combination(0,i,0,new HashSet());
        }
        
        return answer;
    }
    
    static void combination(int idx, int size, int depth, HashSet<Integer> set){
    
        if(depth == size){
            if(!unique(set)){
                return;
            }
            
            for(HashSet<Integer> key : candidateKey){
                if(set.containsAll(key)){
                    return;
                }
            }
            candidateKey.add(set);
            answer++;
            return;
        }
        
        for(int i = idx; i < m; i++){
            HashSet<Integer> newSet = new HashSet<>(set);
            newSet.add(i);
            idx++;
            combination(idx, size, depth + 1, newSet);
        }
    }
    
    static boolean unique(HashSet<Integer> set){
        List<String> list = new ArrayList<>();
        
        for(int i = 0; i < n; i++){
            StringBuilder sb = new StringBuilder();
            
            for(int idx : set){
                sb.append(relationCopy[i][idx]);
            }
            
            if(list.contains(sb.toString())){
                return false;
            }
            
            list.add(sb.toString());
        }
        
        return true;
    }
}
