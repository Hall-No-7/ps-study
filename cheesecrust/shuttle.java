import java.util.*;

class Solution {
    public String solution(int n, int t, int m, String[] timetable) {
        String answer = "";
        
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        
        for(int i = 0; i < timetable.length; i++){
            pq.add(Integer.parseInt(timetable[i].substring(0,2)) * 60 + Integer.parseInt(timetable[i].substring(3,5)));
        }
        
        int startTime = 60 * 9;
        int lastTime = 0;
        int total = 0;
        for(int i = 0; i < n; i++){
            total = 0;
            while(!pq.isEmpty()){
                int tmp = pq.peek();
                
                if(tmp <= startTime && total < m){
                    total += 1;
                    pq.poll();
                }else break;
                
                lastTime = tmp - 1;
            }
            startTime += t;
        }
        
        if(total < m){
            lastTime = startTime - t;
        }
        
        String hour = String.format("%02d", lastTime / 60);
        String minute = String.format("%02d", lastTime % 60);
        
        return hour + ":" + minute;
    }
}
