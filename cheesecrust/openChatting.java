import java.util.*;

class Solution {    
    public String[] solution(String[] record) {
        
        HashMap<String, String> userInfo = new HashMap<String, String>();
        ArrayList<String> moveArr = new ArrayList<String>();
            
        
        int cnt = 0;
        for(String logg : record){
            String[] tmp = logg.split(" ");
            
            if(tmp[0].equals("Enter")){
                userInfo.put(tmp[1], tmp[2]);
            }else if(tmp[0].equals("Change")){
                userInfo.put(tmp[1], tmp[2]);            
                cnt++;
            }
        }
        
        String[] answer = new String[record.length - cnt];

        int idx = 0;
        for(String logg : record){
            String[] tmp = logg.split(" ");
            String nickname = userInfo.get(tmp[1]);
            
            if(tmp[0].equals("Enter")){
                answer[idx++] = nickname + "님이 들어왔습니다.";
            }else if(tmp[0].equals("Leave")){
                answer[idx++] = nickname + "님이 나갔습니다.";
            }
        }
        
        
        return answer;
    }
}
