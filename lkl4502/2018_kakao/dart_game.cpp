#include <bits/stdc++.h>
#define ENDL "\n"
using namespace std;

int num[3];
int bonus[3];
int award[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int totalCount;
    cin >> totalCount;
    for (int i = 0; i < totalCount; i++) {
        string str;
        cin >> str;
        int start = 0, count = 0;

        for (int k = 0; k < str.size(); k++) {
            if (str[k] == 'S' || str[k] == 'D' || str[k] == 'T') {
                start = (k - 2 < 0) ? 0 : k - 2;
                string tmpNum = str.substr(start, 2);
                regex re("\\d+");
                if (!regex_match(tmpNum, re)) {
                    if (start == 0)
                        tmpNum = str.substr(start, 1);
                    else
                        tmpNum = str.substr(start + 1, 1);
                }

                num[count] = stoi(tmpNum);
                if (str[k] == 'S')
                    bonus[count] = 1;
                else if (str[k] == 'D')
                    bonus[count] = 2;
                else
                    bonus[count] = 3;

                if (k + 1 != str.size()) {
                    if (str[k + 1] == '*')
                        award[count] = 2;
                    else if (str[k + 1] == '#')
                        award[count] = -1;
                    else
                        award[count] = 1;
                } else
                    award[count] = 1;
                count++;
            }
        }

        int result = pow(num[0], bonus[0]) * award[0] *
                         ((award[1] == 2) ? award[1] : 1) +
                     pow(num[1], bonus[1]) * award[1] *
                         ((award[2] == 2) ? award[2] : 1) +
                     pow(num[2], bonus[2]) * award[2];

        cout << result << ENDL;

        memset(num, 0, 3 * sizeof(int));
        memset(bonus, 1, 3 * sizeof(int));
        memset(award, 1, 3 * sizeof(int));
    }
}