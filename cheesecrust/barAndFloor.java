import java.util.*;

class Solution {
    static boolean[][] bar;
    static boolean[][] floor;

    public boolean installBar(int y, int x){
        if(y == 0) return true;
        else if(y > 0 && bar[y - 1][x]) return true;
        else if(x > 0 && floor[y][x - 1] || floor[y][x]) return true;
        return false;
    }

    public boolean installFloor(int y, int x){
        if(x > 0 && floor[y][x - 1] && floor[y][x + 1]) return true; // 양쪽이 보로
        else if(y > 0 && bar[y - 1][x] || bar[y - 1][x + 1]) return true; // 한쪽 끝이 바로
        else return false;
    }
    
    public boolean checkDelete(int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(floor[i][j] && installFloor(i,j) == false) return false;
                if(bar[i][j] && installBar(i,j) == false) return false;
            }
        }
        return true;
    }
    
    public int[][] solution(int n, int[][] build_frame) {
        int cnt = 0;
        bar = new boolean[n+1][n+1];
        floor = new boolean[n+1][n+1];
        
        for(int i = 0; i < build_frame.length; i++){
            int x = build_frame[i][0];
            int y = build_frame[i][1];
            int a = build_frame[i][2];
            int b = build_frame[i][3];
            
            if(a == 0){ // bar
                if(b == 1 && installBar(y,x)){
                    bar[y][x] = true; 
                    cnt++;
                }else if(b == 0){
                    bar[y][x] = false;
                    if(checkDelete(n)){
                        cnt--;
                    }
                    else bar[y][x] = true;
                }
            }else if(a == 1){
                if(b == 1 && installFloor(y,x)){
                    floor[y][x] = true;
                    cnt++;
                }else if(b == 0){
                    floor[y][x] = false;
                    if(checkDelete(n)){
                        cnt--;
                    }                    
                    else floor[y][x] = true;
                    
                }
            }
        }
        int[][] answer = new int[cnt][3];
        
        int idx = 0;
        for(int i = 0; i <= n; i++){ // x
            for(int j = 0; j <= n; j++){ // y
                if(bar[j][i]){
                    answer[idx][0] = i; // x
                    answer[idx][1] = j; // y
                    answer[idx++][2] = 0;
                }                
                if(floor[j][i]){
                    answer[idx][0] = i;
                    answer[idx][1] = j;
                    answer[idx++][2] = 1;
                }
            }
        }
        
        return answer;
    }
}
