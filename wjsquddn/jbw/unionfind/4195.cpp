// 생각해보면 간단한 문제
//  친구의 수는 입력으로 들어온 친구의 최상위 부모를 찾아서 높이를 출력해주면 된다.
//  그러므로 필요한 것은 이름과 번호를 저장할 수 있는 map
//  높이 저장 배열
// 서로소 집합
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<string, int> m;
int friendcount[200001];
int parent[200001];
int find_parent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_parent(parent[x]);
}
void make_union(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a < b) {
        parent[b] = a;
        friendcount[a] += friendcount[b];
    } else if (a > b) {
        parent[a] = b;
        friendcount[b] += friendcount[a];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int testcase;
    string str1, str2;
    cin >> testcase;
    map<string, int>::iterator it;

    for (int i = 0; i < testcase; i++) {
        m.clear();
        for (int t = 0; t < 200001; t++) {
            {
                parent[t] = t;
                friendcount[t] = 1;
            }
        }
        int n;
        cin >> n;
        int cnt = 0;
        int a, b;
        for (int j = 0; j < n; j++) {
            cin >> str1 >> str2;
            // 못 찾았을 때
            it = m.find(str1);
            if (it == m.end()) {
                m[str1] = ++cnt;
                a = cnt;
            }
            // 찾았을 때
            else {
                a = it->second;
            }
            it = m.find(str2);
            if (it == m.end()) {
                m[str2] = ++cnt;
                b = cnt;
            }
            // 찾았을 때
            else {
                b = it->second;
            }
            make_union(a, b);
            int root = find_parent(a);
            cout << friendcount[root] << "\n";
        }
    }
    return 0;
}
