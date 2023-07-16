import java.util.*;
import java.io.*;

public class Main {
    static int[] parent;
    static int[][] graph;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N, M;

        int A, B, C;
        int island1;
        int island2;

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        parent = new int[N + 1];

        for (int i = 1; i < N + 1; i++) {
            parent[i] = -1;
        }
        graph = new int[M][3];

        // for(int i = 0; i < M; i++){
        // graph[i]
        // }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());

            graph[i][0] = A;
            graph[i][1] = B;
            graph[i][2] = C;
        }

        Arrays.sort(graph, (i1, i2) -> i2[2] - i1[2]);

        st = new StringTokenizer(br.readLine());
        island1 = Integer.parseInt(st.nextToken());
        island2 = Integer.parseInt(st.nextToken());

        System.out.println(kruscal(island1, island2));

    }

    private static int find(int x) {
        if (parent[x] < 0)
            return x;
        if (parent[x] == x) {
            return x;
        } else {
            return parent[x] = find(parent[x]);
        }
    }

    private static void union(int a, int b) {
        int x = find(a);
        int y = find(b);

        if (x < y) {
            parent[x] += parent[y];
            parent[y] = x;
        } else if (y < x) {
            parent[y] += parent[x];
            parent[x] = y;
        }

        return;
    }

    private static int kruscal(int island1, int island2) {
        int max = graph[0][2];

        for (int i = 0; i < graph.length; i++) {
            if (find(graph[i][0]) != find(graph[i][1])) {
                max = graph[i][2];
                union(graph[i][0], graph[i][1]);
            }

            if (find(island1) == find(island2)) {
                break;
            }
        }

        return max;
    }
}
