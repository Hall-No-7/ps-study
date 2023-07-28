import java.util.*;

class Solution {
    
    public static int answer = 0;
    
    public int solution(String s) {
        int answer = s.length();
        
        for(int i = 1; i <= s.length() / 2; i++){
            int zipLevel = 1;
            String zipWord = s.substring(0,i);
            String result = "";
            
            for(int j = i; j <= s.length(); j += i){
                String next = s.substring(j, j + i > s.length() ? s.length() : j + i);
                if(next.equals(zipWord)){
                    zipLevel++;
                }else{
                    result += (zipLevel == 1 ? "" : Integer.toString(zipLevel)) + zipWord;
                    zipWord = next;
                    zipLevel = 1;
                }
            }
            result += zipWord;
            answer = Math.min(answer, result.length());
        }
        
        return answer;
    }
}
