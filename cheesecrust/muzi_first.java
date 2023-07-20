import java.util.*;

class Solution {
    public int solution(int[] food_times, long k) {
        int answer = 0;
        
        int n = food_times.length;
        long sum = 0;
        
        for(int i = 0 ; i < n; i++){
            sum += food_times[i];
        }
        
        while(k > 0){
            if(sum == 0){
                return -1;
            }
            if(food_times[answer] == 0){
                answer = (answer + 1) % n;
                continue;
            }else{
                food_times[answer] -= 1;            
                k--;
                sum--;
                answer = (answer + 1) % n;
            }            
        }
        
        if(sum == 0){
            return -1;
        }
        
        while(food_times[answer] == 0){
            answer = (answer + 1) % n;
        }
        
        answer += 1;
        return answer;
    }
}
