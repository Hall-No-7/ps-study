import java.util.*;
import java.io.*;

public class Main {
    static int[] digitY = { -1, 0, 1, 0 };
    static int[] digitX = { 0, 1, 0, -1 };
    static int[][] map;
    static int R, C;
    static boolean[] visit = new boolean[26];

    static int max = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        map = new int[R][C];

        for (int i = 0; i < R; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < C; j++) {
                map[i][j] = tmp.charAt(j) - 'A';
            }
        }

        traverse(0, 0, 0);

        System.out.println(max);
    }

    public static void traverse(int curY, int curX, int cnt) {

        if (visit[map[curY][curX]]) {
            if (max < cnt)
                max = cnt;
            return;
        }

        visit[map[curY][curX]] = true;

        for (int i = 0; i < 4; i++) {
            int nextY = curY + digitY[i];
            int nextX = curX + digitX[i];

            if (nextX >= 0 && nextY >= 0 && nextX < C && nextY < R) {
                traverse(nextY, nextX, cnt + 1);
            }

        }
        visit[map[curY][curX]] = false;

    }
}
