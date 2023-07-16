import java.util.HashMap;
import java.util.Scanner;
import java.util.ArrayList;

class Solution {
    public int[] solution(String msg) {
        int dicSize = 1;
        
        ArrayList<Integer> ans = new ArrayList<>();
        HashMap<String, Integer> dic = new HashMap<String, Integer>();
        
        for(char i = 'A'; i <= 'Z'; i++){
            dic.put(Character.toString(i), dicSize);
            dicSize++;
        }
        
        Boolean isEnd = false;
        
        for(int i = 0; i < msg.length(); i++){
            String word = msg.charAt(i) + "";
            while(dic.containsKey(word)){
                i++;
    
                if(i == msg.length()){
                    isEnd = true;
                    break;
                }
                word += msg.charAt(i);
            }
            
            if(isEnd){
                ans.add(dic.get(word));
                break;
            }
        
            ans.add(dic.get(word.substring(0,word.length() - 1)));
            dic.put(word, dicSize);
            dicSize++;
            
            i--;
        }
        
        int[] answer = new int[ans.size()];
        for(int i = 0 ; i < answer.length ; i++){
            answer[i] = ans.get(i);
        }
      
        return answer;
    }
}
