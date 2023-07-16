//-----------------개념코드----------------------

#include <iostream>
using namespace std;
//------- 초기화 -------
int MAX_SIZE = 10;
int rank[MAX_SIZE];
int root[MAX_SIZE];
for (int i = 0; i < MAX_SIZE; i++)
{
    root[i] = i;
    rank[i] = 0;
}

int find(int x)
{
    if (root[x] == x)
    {
        return x;
    }
    else
    {
        return root[x] = find(root[x]);
        // find하면서 만나는 모든 값의 부모 노드를 root로 만든다.
    }
}
void union(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return;
    }
    if (rank[x] < rank[y])
    {
        root[x] = y;
    }
    else
    {
        root[y] = x;
    }
    if (rank[x] == rank[y])
    {
        rank[x]++;
    }
}
int main()
{
    return 0;
}