#include <iostream>
using namespace std;

long long a[1000001];
int main() {
    int n;
    cin >> n;
    int cnt = 10;
    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < a[i] % 10; j++) {
            a[cnt++] = a[i] * 10 + j;
        }
    }
    if (n > 1022)
        cout << -1;
    else {
        cout << a[n];
    }
}