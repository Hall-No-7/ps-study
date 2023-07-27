import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class SegmentTree {
        long tree[];
        int treeSize;

        public SegmentTree(int arrSize) {
            int height = (int) Math.ceil(Math.log(arrSize) / Math.log(2));
            this.treeSize = (int) Math.pow(2, height + 1);

            this.tree = new long[treeSize];
        }

        public long init(long[] arr, int idx, int start, int end) {
            if (start == end) {
                return tree[idx] = arr[start];
            }

            return tree[idx] = init(arr, idx * 2, start, (start + end) / 2)
                    + init(arr, idx * 2 + 1, (start + end) / 2 + 1, end);
        }

        public long sum(int idx, int start, int end, long left, long right) {
            if (left > end || start > right) {
                return 0;
            }
            if (left <= start && end <= right) {
                return tree[idx];
            }

            return sum(idx * 2, start, (start + end) / 2, left, right)
                    + sum(idx * 2 + 1, (start + end) / 2 + 1, end, left, right);
        }

        public long update(int node, int start, int end, int idx, long diff) {
            if (idx < start || end < idx) {
                return tree[node];
            }

            if (start == end) {
                return tree[node] += diff;
            }

            return tree[node] = update(node * 2, start, (start + end) / 2, idx, diff) +
                    update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
        }

    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N, Q;

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        SegmentTree segmentTree = new SegmentTree(N);
        long[] arr = new long[N + 1];

        segmentTree.init(arr, 1, 1, N);

        int num;
        long p, q;
        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());

            num = Integer.parseInt(st.nextToken());
            p = Long.parseLong(st.nextToken());
            q = Long.parseLong(st.nextToken());

            if (num == 1) {
                segmentTree.update(1, 1, N, (int) p, q);
            } else if (num == 2) {
                System.out.println(segmentTree.sum(1, 1, N, p, q));
            }
        }
    }
}
