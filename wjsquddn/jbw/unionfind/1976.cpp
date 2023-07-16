// union find로 풀면 된다.
#include <iostream>
using namespace std;
int parent[1001];

int find_parent(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find_parent(parent[x]);
}

void make_union(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a == b) return;
    if (a < b) {
        parent[b] = a;
        find_parent(b);
    } else {
        parent[a] = b;
        find_parent(a);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    //-- 배열 초기화--//
    for (int i = 0; i < 1001; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int join;
            cin >> join;
            if (join == 1) make_union(i, j);
        }
    }
    int cnt;
    cin >> cnt;
    int now;
    bool flag = true;
    for (int i = 1; i < m; i++) {
        cin >> now;
        if (find_parent(now) != find_parent(cnt)) {
            flag = false;
            break;
        }
        cnt = now;
    }
    if (flag == true)
        cout << "YES";
    else {
        cout << "NO";
    }
    // int past, here;
    // bool canTrip = true;
    // cin >> past;
    // for (int i = 1; i < m; i++) {
    //     cin >> here;
    //     if (!canTrip) continue;
    //     if (find_parent(past) != find_parent(here)) canTrip = false;
    //     past = here;
    // }
    // if (canTrip)
    //     cout << "YES";
    // else
    //     cout << "NO";
}