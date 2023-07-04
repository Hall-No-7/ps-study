#include <iostream>
#include <stack>
using namespace std;
int length = 26;
int ALPHA[26];

int main()
{
    stack<char> st;
    string a;
    cin >> a;
    for (int i = 0; i < a.length(); i++)
    {
        int cnt = a[i] - 65;
        ALPHA[cnt]++;
    }
    int odd = 0, even = 0;
    //----------------check possible--------------------
    for (int i = 0; i < length; i++)
    {
        if (ALPHA[i] == 0)
        {
            continue;
        }
        else if (ALPHA[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    if (odd > 1)
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    //-------------------------------------------------
    char forodd = 0;
    for (int i = 0; i < length; i++)
    {
        if (ALPHA[i] == 0)
        {
            continue;
        }
        else if (ALPHA[i] % 2 == 0)
        {
            for (int j = 0; j < ALPHA[i] / 2; j++)
            {
                cout << char(i + 65);
            }
            for (int j = 0; j < ALPHA[i] / 2; j++)
            {
                st.push(char(i + 65));
            }
        }
        else if (ALPHA[i] % 2 != 0)
        {
            for (int j = 0; j < ALPHA[i] / 2; j++)
            {
                cout << char(i + 65);
            }
            for (int j = 0; j < ALPHA[i] / 2; j++)
            {
                st.push(char(i + 65));
            }
            forodd = char(i + 65);
        }
    }
    //------------------------------출력 ----------------------------
    int asdf = st.size();
    //------------------여기서 조건문 넣어주는 거 안해서 30 분 걸림----------------
    if (forodd != 0)
    {
        cout << forodd;
    }
    //-------------------------------------------------------------------------

    for (int i = 0; i < asdf; i++)
    {
        cout << st.top();
        st.pop();
    }
    //---------------------------------------------------------------
}