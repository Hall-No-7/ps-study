#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string getkjinsoo(int n, int k) {
    string s;
    while (n > 0) {
        s += to_string(n % k);
        n = n / k;
    }
    reverse(s.begin(), s.end());
    return s;
}
bool checkingprime(long long n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string s = getkjinsoo(n, k);
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (!temp.empty() && s[i] == '0') {
            if (checkingprime(stoll(temp))) {
                answer++;
            }
            temp = "";
        } else {
            temp += s[i];
        }
    }
    if (!temp.empty()) {
        if (checkingprime(stoll(temp))) {
            answer++;
        }
    }
    return answer;
}
int main() {
    int n = 437674;
    int k = 3;
    cout << solution(n, k);
}