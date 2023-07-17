import java.util.*;

class Solution {    
    public String[] solution(String[] record) {
        
        HashMap<String, String> userInfo = new HashMap<String, String>();
        ArrayList<String> moveArr = new ArrayList<String>();
            
        for(String logg : record){
            String[] tmp = logg.split(" ");
            
            if(tmp[0].equals("Enter")){
                userInfo.put(tmp[1], tmp[2]);
                moveArr.add(tmp[1] + "님이 들어왔습니다.");    
                
            }else if(tmp[0].equals("Leave")){
                moveArr.add(tmp[1] + "님이 나갔습니다.");           
                
            }else if(tmp[0].equals("Change")){
                userInfo.put(tmp[1], tmp[2]);            
            }
        }
        
        for(Map.Entry<String, String> entry : userInfo.entrySet()){
            for(int i = 0; i < moveArr.size(); i++){
                String move = moveArr.get(i);
                moveArr.set(i,move.replace(entry.getKey(), entry.getValue()));
            } 
        }
        
        int n = moveArr.size();
        String[] answer = new String[moveArr.size()];

        for(int i = 0; i < n; i++){
            answer[i] = moveArr.get(i);
        }
        
        
        return answer;
    }
}
