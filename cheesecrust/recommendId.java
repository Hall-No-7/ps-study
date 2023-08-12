import java.util.*;

class Solution {
    public String solution(String new_id) {
        String lowerCaseId = new_id.toLowerCase(); // 1단계
        
        String secondId = "";
        for(int i = 0; i < lowerCaseId.length(); i++){
            char word = lowerCaseId.charAt(i);
            
            if(word == '_' || word == '.' || word == '-' || (word >= 'a' && 'z' >= word) || (word >= '0' && '9' >= word))
                secondId += word;
        }
                
        String thirdId = secondId.toString().replace("..", ".");
        while(thirdId.contains("..")){
            thirdId = thirdId.replace("..", ".");
        }
        
        
        String fourthId = thirdId;
        
        if(fourthId.length() > 0){
            if(fourthId.charAt(0) == '.'){
                fourthId = fourthId.substring(1, fourthId.length());
            }
        }
        if(fourthId.length() > 0){
            if(fourthId.charAt(fourthId.length() - 1) == '.'){
                fourthId = fourthId.substring(0,fourthId.length() - 1);
            }       
        }
        
        String fifthId = fourthId;
        if(fifthId.equals("")){
            fifthId = "a";
        }
        
        String sixId = fifthId;
        
        if(sixId.length() >= 16){
            sixId = sixId.substring(0,15);
            if(sixId.charAt(14) == '.'){
                sixId = sixId.substring(0,14);   
            }
        }

        String finalId = sixId;
        
        char lastWord = finalId.charAt(finalId.length() - 1); 
        
        while(finalId.length() < 3){
            finalId += lastWord;
        }
        return finalId;
    }
}
