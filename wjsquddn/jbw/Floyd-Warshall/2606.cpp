#include <iostream>
#include <vector>
using namespace std;
vector<int> A[101];
bool check[101];
int cnt = 0;
void dfs(int x) {
    check[x] = true;
    for (int i = 0; i < A[x].size(); i++) {
        int y = A[x][i];
        if (!check[y]) {
            dfs(y);
            cnt++;
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    dfs(1);
    cout << cnt << endl;
}