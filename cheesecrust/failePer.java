import java.util.*;
import java.io.*;

class Solution {
    static class Rate{
        int idx;
        double rate;
        
        public Rate(int idx, double rate){
            this.idx = idx;
            this.rate = rate;
        }
    }
    
    public int[] solution(int N, int[] stages) {
        int[] answer = new int[N];

        int[] playerCnt = new int[N + 2];
        int[] failPlayer = new int[N + 2];
        
        for(int stage : stages){
            failPlayer[stage]++;
            for(int i = 1; i <= stage; i++){
                playerCnt[i]++;
            }
        }
        
        ArrayList<Rate> rates = new ArrayList<>();
        
        for(int i = 1; i <= N; i++){
            if(playerCnt[i] == 0){
                rates.add(new Rate(i, 0));
                continue;
            }
            
            double rate = (double) failPlayer[i] / playerCnt[i];
            rates.add(new Rate(i, rate));
        }

        Collections.sort(rates, (o1,o2) -> Double.compare(o2.rate , o1.rate));
        
        for(int i = 0; i < rates.size(); i++){
            answer[i] = rates.get(i).idx;
        }
        return answer;
    }
}
