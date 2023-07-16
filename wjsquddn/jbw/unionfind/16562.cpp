#include <iostream>
using namespace std;
int A[100001];
int parent[10001];
bool visit[10001];

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}
void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return;
    }
    if (A[a] < A[b]) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}
int main() {
    int money = 0;
    for (int i = 0; i < 10001; i++) {
        parent[i] = i;
        visit[i] = false;
    }
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;
        A[i] = cnt;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    for (int i = 1; i <= n; i++) {
        int p = find(i);
        if (!visit[p]) {
            money += A[p];
            visit[p] = true;
        }
    }
    if (money > k) {
        cout << "Oh no";
    } else {
        cout << money;
    }
    return 0;
}