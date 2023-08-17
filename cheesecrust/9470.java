import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int T;
    static int K, M, P;

    static int[] degree;
    static int[] order;
    static int[] cnt;
    static ArrayList<Integer>[] graph;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());

            K = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            P = Integer.parseInt(st.nextToken());

            degree = new int[M + 1];
            order = new int[M + 1];
            cnt = new int[M + 1];

            graph = new ArrayList[M + 1];
            for (int i = 1; i <= M; i++) {
                graph[i] = new ArrayList<Integer>();
            }

            for (int i = 0; i < P; i++) {
                st = new StringTokenizer(br.readLine());

                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());

                graph[x].add(y);
                degree[y]++;
            }

            solution();
        }
    }

    public static void solution() {
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int i = 1; i <= M; i++) {
            if (degree[i] == 0) {
                pq.add(i);
                order[i]++;
                cnt[i]++;
            }
        }

        int answer = 0;

        while (!pq.isEmpty()) {
            int x = pq.poll();

            if (cnt[x] >= 2)
                order[x]++;

            answer = Math.max(answer, order[x]);
            for (int idx : graph[x]) {
                if (--degree[idx] == 0) {
                    pq.add(idx);
                }

                if (order[idx] < order[x]) {
                    order[idx] = order[x];
                    cnt[idx] = 1;
                } else if (order[idx] == order[x]) {
                    cnt[idx]++;
                }
            }
        }

        System.out.print(K);
        System.out.print(" ");
        System.out.println(answer);
    }
}
