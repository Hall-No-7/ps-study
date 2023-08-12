import java.util.*;

class Solution {
    static int N;
    static int trunk;
    static int[][] graph;
    
    public int solution(int n, int s, int a, int b, int[][] fares) {
        N = n;
        trunk = fares.length;
        graph = new int[n][n];
        
        for(int i = 0; i < trunk; i++){
            int start = fares[i][0] - 1;
            int next = fares[i][1] - 1;
            int cost = fares[i][2];
            
            graph[start][next] = cost;
            graph[next][start] = cost;
        }
        
        int[] together = dijkstra(s - 1); // s 출발지점, 위에서 1 빼서 사용, 출발 지점으로 부터 각 지점까지의 비용
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < N; i++){ // 각 정점으로 부터 비용 계산
            int[] solo = dijkstra(i);
            int cost = together[i] + solo[a - 1] + solo[b - 1]; // 각 정점을 경유
            if(cost < min){
                min = cost;
            }
        }
        
        
        return min;
    }
    
    public int[] dijkstra(int start){
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        boolean[] visited = new boolean[N];
        int[] distance = new int [N];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[start] = 0;
        pq.add(new int[] {0,start}); // cost, 시작점
        
        while(!pq.isEmpty()){
            int[] cur = pq.remove();
            int u = cur[1]; // 시작점
            if(visited[u]) continue; // 방문 했으면 지나감
            
            visited[u] = true;
            
            for(int i = 0; i < N; i++){
                if(graph[u][i] == 0) continue; // 길이 없으면 못 지나감
                
                if(distance[u] + graph[u][i] < distance[i]){
                    distance[i] = distance[u] + graph[u][i];
                    pq.add(new int[] {distance[i], i});
                }
            }
        }
        
        return distance;
    }
}
