// By Hongs
#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

int main() {
    fast_io;
    int n, a, b;
    cin >> n;
    vector<vector<int>> friends(n + 1, vector<int>(n + 1, n));
    for (int i = 1; i <= n; i++)
        friends[i][i] = 0;
    while (true) {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        friends[a][b] = 1;
        friends[b][a] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                friends[i][j] =
                    min(friends[i][j], friends[i][k] + friends[k][j]);

    vector<int> score(n + 1);
    for (int i = 1; i <= n; i++)
        score[i] = *max_element(friends[i].begin() + 1, friends[i].end());

    int chairManScore = *min_element(score.begin() + 1, score.end());
    vector<int> answer;
    for (int i = 1; i <= n; i++)
        if (score[i] == chairManScore)
            answer.push_back(i);
    cout << chairManScore << " " << answer.size() << endl;
    for (int &ele : answer)
        cout << ele << " ";
}