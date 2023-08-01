import java.util.*;

class Solution {
    static int[] weakArr, distArr;
    static int[] choice;
    static int[][] rotateWeak;
    
    static int num = 0;
    static int answer = 0;
    
    public void check(){
        for(int[] weak_case : rotateWeak){
            int cur = 0, next;
            int dist_idx = 0;
            while(cur < weak_case.length && dist_idx < choice.length){
                next = cur+1;
                while(next < weak_case.length &&
                        weak_case[cur] + choice[dist_idx] >= weak_case[next]){
                   next++;
                }
                cur = next;
                dist_idx++;
            }

            if(cur == weak_case.length && dist_idx < answer)
                answer = dist_idx;
        }        
    }
    
    
    public void makeWeakArr(){
        int len = weakArr.length;
        
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                rotateWeak[i][j] = (i + j >= len ? num + weakArr[(i + j) % len] : weakArr[i + j]);
            }   
        }
    }
    
    public void premention(int depth, boolean[] visited){
        if(depth == distArr.length){
            check();
            return;
        }
        
        for(int i = 0; i < distArr.length; i++){
            if(!visited[i]){
                choice[depth] = distArr[i];
                visited[i] = true;
                premention(depth + 1, visited);
                visited[i] = false;
            }
        }
    }
    
    public int solution(int n, int[] weak, int[] dist) {
        answer = 2147000000;
        num = n;
        
        weakArr = weak;
        distArr = dist;
        rotateWeak = new int[weak.length][weak.length];
        
        choice = new int[dist.length];
    
        makeWeakArr();
    
        premention(0, new boolean[dist.length]);
        
        if(answer == 2147000000){
            return -1;    
                }else{
        return answer;
            
        }
    }
}
