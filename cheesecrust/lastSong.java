import java.util.*;

class Solution {
    public Integer makeTime(String time){
        Integer tmp = Integer.parseInt(time.substring(0,2)) * 60 + Integer.parseInt(time.substring(3,5));

        return tmp;
    }
    
    public String makeMelody(String melody){
        melody = melody.replaceAll("C#", "H");
        melody = melody.replaceAll("D#", "I");
        melody = melody.replaceAll("F#", "G");
        melody = melody.replaceAll("G#", "K");
        String newMelody = melody.replaceAll("A#", "L");
        
        return newMelody;   
    }
    
    public String solution(String m, String[] musicinfos) {
        String answer = "(None)";
        int maxPlayTime = -1;
        
        String inputMelody = makeMelody(m);
        
        for(int i = 0; i < musicinfos.length; i++){
            String[] musicinfo = musicinfos[i].split(",");
            
            String title = musicinfo[2];
            
            Integer totalTime = makeTime(musicinfo[1]) - makeTime(musicinfo[0]);
            
            String melodyInfo = makeMelody(musicinfo[3]);
            
            int melodyLength = melodyInfo.length();
            
            String totalMelody = ""; 
            
            for(int j = 0; j < (totalTime / melodyLength); j++){
                totalMelody += melodyInfo;
            }
            
            totalMelody += melodyInfo.substring(0,totalTime % melodyLength);
            
            if(totalMelody.contains(inputMelody) && totalTime > maxPlayTime){
                answer = title;
                maxPlayTime = totalTime;
            }
        }
        return answer;
    }
}
