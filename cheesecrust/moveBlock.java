import java.util.*;

class Solution {
    static int answer = 2147000000;
    static int n = 0;
    
    static int[][] newBoard;
    static boolean[][][] visited = new boolean[2][101][101];
    
    static int[] dirY = {-1,1,0,0};
    static int[] dirX = {0,0,-1,1};
    
    static int[][] rotateY = {{-1,0,-1,0}, {0,0,1,1}}; // 가로 세로
    static int[][] rotateX = {{0,0,1,1}, {-1,0,-1,0}}; // 가로 세로
    
    public void bfs(){
        Queue<Pair> queue = new LinkedList<>();
        
        queue.add(new Pair(0,0,0,0));
        visited[0][0][0] = true;
        
        while(!queue.isEmpty()){
            Pair p = queue.poll();
            
            int y = p.y;
            int x = p.x;
            int dir = p.dir;
            int cnt = p.cnt;
            
            if(dir == 0 && y == n - 1 && x == n - 2){
                answer = Math.min(answer, cnt);
                continue;
            }
            if(dir == 1 && y == n - 2 && x == n - 1){
                answer = Math.min(answer, cnt);
                continue;
            }
            
            for(int i = 0; i < 4; i++){ //이동
                int ny = y + dirY[i];
                int nx = x + dirX[i];
                
                if(!checkMove(ny, nx, dir)) continue;
                
                if(!visited[dir][ny][nx]){
                    visited[dir][ny][nx] = true;
                    queue.add(new Pair(ny,nx,dir,cnt+1));
                }
            }
            for(int i = 0; i < 4; i++){ // 회전
                int ny = y + rotateY[dir][i];
                int nx = x + rotateX[dir][i];
                int cy = 0;
                int cx = 0;
                
                int ndir = 0;
                if(dir == 0){
                    ndir = 1;
                    cy = y + dirY[i % 2];
                    cx = x + dirX[i % 2];            
                }else if(dir == 1){
                    ndir = 0;
                    cy = y + dirY[2 + i % 2]; 
                    cx = x + dirX[2 + i % 2]; 
                }
                
                if(!checkMove(ny, nx, ndir) || !checkMove(cy, cx, dir)) continue;
                
                if(!visited[ndir][ny][nx]){
                    queue.add(new Pair(ny,nx,ndir, cnt+1));
                    visited[ndir][ny][nx] = true;
                }
            }
        }
    }
    
    public boolean checkMove(int ny, int nx, int dir){
        if(dir == 0){ // 가로
            if(ny < 0 || nx < 0 || ny >= n || nx >= n || nx + 1 >= n || newBoard[ny][nx] != 0 || newBoard[ny][nx + 1] != 0) return false;
        }else{ // 세로
            if(ny < 0 || nx < 0 || ny >= n || nx >= n || ny + 1 >= n || newBoard[ny][nx] != 0 || newBoard[ny + 1][nx] != 0) return false;
        }
        
        return true;
    }
    
    public int solution(int[][] board) {
        n = board.length;
        newBoard = board;
                        
        bfs();
        
        return answer;
    }
    
    static class Pair{
        int y = 0;
        int x = 0;
        int dir = 0; // 가로는 0, 세로는 1
        int cnt = 0;
        
        public Pair(int y, int x, int dir, int cnt){
            this.y = y;
            this.x = x;
            this.dir = dir;
            this.cnt = cnt;
        }
    }    
}
