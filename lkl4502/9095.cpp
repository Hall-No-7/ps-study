#include <bits/stdc++.h>
#define ENDL "\n"
using namespace std;

int cnt = 0;

void cal(int x) {
    if (x < 0)
        return;

    if (x == 0) {
        cnt++;
        return;
    }

    cal(x - 1);
    cal(x - 2);
    cal(x - 3);
}

int main() {
    int totalCount;
    cin >> totalCount;
    for (int i = 0; i < totalCount; i++) {
        cnt = 0;
        int x;
        cin >> x;
        cal(x);
        cout << cnt << ENDL;
    }
}