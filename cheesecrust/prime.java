import java.util.*;

class Solution {
    static int answer;
    
    public int solution(int n, int k) {
        answer = 0;
        
        convertToK(n,k);
        
        return answer;
    }
    
    public boolean isPrime(Long num){
        
        if(num < 2) return false; // 소수가 아니면 false
        
        for(int i = 2; i <= Math.sqrt(num); i++){
            if(num % i == 0) return false;
        }
        return true;
    }
    
    public void convertToK(int n, int k){
        String result = "";
        
        while(n > 0){
            result = n % k + result;
            n /= k;
        }
        
        for(String tmp : result.split("0")){
            
            if(tmp.equals("")) continue;

            long idx = Long.parseLong(tmp); // 1000000 보다 큰 수 여도 소수면 ok 그래서 에라토스를 만들어 놓고 쓸 수 가 없다.
            
            if(isPrime(idx)){ // 소수
                answer += 1;
            }

        }
        
    }
    
    
}
