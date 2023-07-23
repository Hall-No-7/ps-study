// 이건 백트랙킹 문제가 아닌것 같다.
// 그냥 규칙만 알면 간단히 풀 수 있는 문제
#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);

    if (n % 6 == 2) {
        for (int i = 1; i <= (n / 2); i++) {
            printf("%d\n", 2 * i);
        }
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                if (i == 1) continue;
                if (i == 3) {
                    printf("%d\n", i);
                    printf("%d\n", i - 2);
                    continue;
                }
                if (i == 5) continue;

                printf("%d\n", i);
            }
        }
        printf("%d\n", 5);
    } else if (n % 6 == 3) {
        for (int i = 1; i <= (n / 2); i++) {
            if (i == 1) continue;
            if (i == n / 2) {
                printf("%d\n", i * 2);
                printf("%d\n", 2);
                continue;
            }
            printf("%d\n", i * 2);
        }
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                if (i == 1 || i == 3) {
                    continue;
                }
                printf("%d\n", i);
            }
        }
        printf("%d\n", 1);
        printf("%d\n", 3);
    } else {
        for (int i = 1; i <= (n / 2); i++) {
            printf("%d\n", i * 2);
        }
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                printf("%d\n", i);
            }
        }
    }
}