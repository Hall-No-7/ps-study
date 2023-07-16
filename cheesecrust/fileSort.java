import java.util.*;

class Solution {
    public String[] solution(String[] files) {
        
        Arrays.sort(files, new Comparator<String>() {
            public int compare(String i1, String i2) {
                String[] file1 = detach(i1);
                String[] file2 = detach(i2);
                
                int headValue = file1[0].compareTo(file2[0]);
                
                if(headValue == 0){
                    int value1 = Integer.parseInt(file1[1]);
                    int value2 = Integer.parseInt(file2[1]);
                    
                    return value1 - value2;
                }else{
                    return headValue;
                }                
            }
            
            private String[] detach(String str){
                String head = "";
                String number = "";
                
                int flag = 0;
                for(int i = 0; i < str.length(); i++){
                    if('0' <= str.charAt(i) && str.charAt(i) <= '9'){
                        flag = 1;
                    }else if (flag == 1){
                        flag = 2;
                    }
                    
                    if(flag == 0){
                        head += str.charAt(i);
                    }else if(flag == 1){
                        number += str.charAt(i);
                    }else{
                        break;
                    }
                }
                
                String[] file = {head.toUpperCase(), number};
                
                return file;
            }
        });
        
        return files;
    }
}
