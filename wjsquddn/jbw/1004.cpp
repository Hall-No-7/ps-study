#include <iostream>
using namespace std;
//------ dp 배열 -----------
long long arr[100] = {0, 1, 1};
//---------------------------
void fibo(int n)
{
    if (n == 0)
    {
        cout << "1 0" << endl;
        return;
    }
    cout << arr[n - 1] << " " << arr[n] << endl;
    return;
}
int main()
{
    int n;
    cin >> n;
    //--------------DP 배열 생성------------
    for (int i = 3; i < 50; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    //---------------------------------------
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        fibo(a);
    }
}
