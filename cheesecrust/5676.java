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
                    * init(arr, idx * 2 + 1, (start + end) / 2 + 1, end);
        }

        public long multiply(int idx, int start, int end, long left, long right) {
            if (left > end || start > right) {
                return 1;
            }
            if (left <= start && end <= right) {
                return tree[idx];
            }

            return multiply(idx * 2, start, (start + end) / 2, left, right)
                    * multiply(idx * 2 + 1, (start + end) / 2 + 1, end, left, right);
        }

        public long update(int node, int start, int end, int idx, long diff) {
            if (idx < start || end < idx) {
                return tree[node];
            }

            if (start == end) {
                return tree[node] = diff;
            }

            return tree[node] = update(node * 2, start, (start + end) / 2, idx, diff) *
                    update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
        }

    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            String s = br.readLine();

            if (s == null)
                break;
            StringTokenizer st = new StringTokenizer(s);

            int N, K;

            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            long[] arr = new long[N + 1];

            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                long tmp = Long.parseLong(st.nextToken());
                arr[i] = (tmp == 0) ? 0 : (tmp > 0) ? 1 : -1;
            }

            SegmentTree segmentTree = new SegmentTree(N);

            segmentTree.init(arr, 1, 1, N);

            char command = ' ';
            long numI;
            long numV;

            for (int i = 0; i < K; i++) {
                st = new StringTokenizer(br.readLine());

                command = st.nextToken().charAt(0);
                numI = Long.parseLong(st.nextToken());
                numV = Long.parseLong(st.nextToken());

                if (command == 'P') {// multiply
                    long result = (segmentTree.multiply(1, 1, N, numI, numV));

                    if (result == 0) {
                        System.out.print("0");
                    } else if (result > 0) {
                        System.out.print("+");
                    } else if (result < 0) {
                        System.out.print("-");
                    }
                } else if (command == 'C') { // change
                    if (numV == 0) {
                        numV = 0;
                    } else if (numV < 0) {
                        numV = -1;
                    } else if (numV > 0) {
                        numV = 1;
                    }
                    segmentTree.update(1, 1, N, (int) numI, numV);
                }
            }

            System.out.println();
        }

    }
}
