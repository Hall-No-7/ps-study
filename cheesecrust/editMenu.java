import java.util.*;
import java.util.Map.Entry;

class Solution {
    
    static HashMap<String, Integer> map = new HashMap<>();
    static boolean[] check;
    
    public void premention (String order, String menu, int len, int start, int n){
        if(len == n){
            map.put(menu, map.getOrDefault(menu, 0) + 1);
            return;
        }
        
        for(int i = start; i < order.length(); i++){
            if(check[i] == false){
                check[i] = true;
                premention(order, menu + order.charAt(i), len + 1, i, n);
                check[i] = false;
            }            
        }
    }
    
    
    public ArrayList<String> solution(String[] orders, int[] course) {
        ArrayList<String> answer = new ArrayList<>();
        
        for(int i = 0; i < orders.length; i++){
            char[] tmp = orders[i].toCharArray();
            Arrays.sort(tmp);
            orders[i] = String.valueOf(tmp);
        }
        
                
        for(int courseCnt : course){
            
            map = new HashMap<>();
            
            int max = 0;
            for(String order : orders){
                check = new boolean[order.length()];
                premention(order, "", 0, 0, courseCnt);
            }
            
            for(Entry<String, Integer> entry : map.entrySet()){
                max = Math.max(max, entry.getValue());
            }
            
            for(Entry<String, Integer> entry : map.entrySet()){
                if(max >= 2 && entry.getValue() == max){
                    answer.add(entry.getKey());
                }
            }   
        }
        
        Collections.sort(answer);
        
        return answer;
    }
}
