// 집합의 표현 unionfind 기본문제
// scanf printf로 풀어야지 시간초과 안나네 이것 때문에 1시간 날림
// 높이고려하는 걸로 짜봤는데 시간초과 남
#include <iostream>
using namespace std;
int Set[1000001];

int find(int a)
{
    if (Set[a] == a)
    {
        return a;
    }
    else
    {
        Set[a] = find(Set[a]);
        return Set[a];
    }
}
void Union(int b, int c)
{
    b = find(b);
    c = find(c);
    if (b == c)
    {
        return;
    }

    Set[b] = c;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 1000001; i++)
    {
        Set[i] = i;
    }
    for (int j = 0; j < m; j++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0)
        {
            Union(b, c);
        }
        else
        {
            if (find(b) == find(c))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}