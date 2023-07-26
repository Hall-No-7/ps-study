#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

int main() {
    fast_io;
    string s = "abcabcabcabcdededededede";
    int shortest = s.length();

    for (int len = s.size() / 2; len > 0; len--) {
        string result, str;
        int count = 0;
        for (auto it = s.begin(); it != s.end(); it += len) {
            if (s.end() - it < len) {
                if (count == 1)
                    result += str;
                else if (count > 1)
                    result += to_string(count) + str;
                result += s.substr(it - s.begin());
                count = 0;
                break;
            }
            string tmp = s.substr(it - s.begin(), len);
            if (count == 0)
                str = s.substr(it - s.begin(), len);

            if (tmp == str) {
                count++;
                continue;
            }

            if (count == 1)
                result += str;
            else
                result += to_string(count) + str;
            str = string(tmp);
            count = 1;
        }
        if (count > 0) {
            if (count == 1)
                result += str;
            else
                result += to_string(count) + str;
        }

        cout << result << " " << len << endl;

        if (shortest > result.length())
            shortest = result.length();
    }
    cout << shortest << endl;
}