import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static boolean[] visit;

    static int[] degree;

    static PriorityQueue<Integer> pq = new PriorityQueue<Integer>();

    static HashMap<Integer, int[]> graph = new HashMap<Integer, int[]>();

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        visit = new boolean[N + 1];
        degree = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            degree[a]++;
            degree[b]++;

            graph.put(i, new int[] { a, b });
        }

        for (int i = 1; i <= N; i++) {
            if (degree[i] < 2) {
                pq.add(i);
            }
        }

        while (!pq.isEmpty()) {
            int now = pq.poll();
            if (visit[now])
                continue;

            visit[now] = true;

            int a = graph.get(now)[0];
            int b = graph.get(now)[1];

            if (--degree[a] < 2)
                pq.add(a);

            if (--degree[b] < 2)
                pq.add(b);
        }

        int cnt = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= N; i++) {
            if (degree[i] == 2) {
                cnt++;
                sb.append(i + " ");
            }
        }

        System.out.println(cnt);
        System.out.println(sb.toString());
    }
}
