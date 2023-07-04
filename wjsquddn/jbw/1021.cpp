#include <iostream>
#include <deque>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int left, right;
    int cnt = 0;
    deque<int> dq;
    for (int i = 1; i < n + 1; i++)
    {
        dq.push_back(i);
    }
    // cout << dq.size();
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        // --------- 첫번째 원소에 그냥 있는 경우 -------
        if (dq.front() == a)
        {
            dq.pop_front();
            // cout << dq.size() << endl;
            // for (int i = 0; i < dq.size(); i++)
            // {
            //     cout << dq[i] << " ";
            // }
            continue;
        }
        else
        {
            //----왼쪽이랑 가까운지 오른쪽이랑 가까운지 판별 -----
            for (int i = 0; i < dq.size(); i++)
            {
                if (dq[i] == a)
                {
                    left = i;
                    right = dq.size() - i;
                }
            }
            if (left <= right)
            {
                while (dq.front() != a)
                {
                    dq.push_back(dq.front());
                    dq.pop_front();
                    cnt++;
                    if (dq.front() == a)
                    {
                        dq.pop_front();
                        break;
                    }
                }
            }
            else if (left > right)
            {

                while (dq.front() != a)
                {
                    dq.push_front(dq.back());
                    dq.pop_back();
                    cnt++;
                    if (dq.front() == a)
                    {
                        dq.pop_front();
                        break;
                    }
                }
            }
        }
    }
    cout << cnt;
    return 0;
}