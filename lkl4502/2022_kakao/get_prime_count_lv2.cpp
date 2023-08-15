#include <string>
#include <vector>
using namespace std;

string Convert(int n, int k) {
    string result;
    for (int i = n; i > 0;) {
        result = to_string(i % k) + result;
        i /= k;
    }
    return result;
}

bool isPrime(long long n) {
    if (n < 2)
        return false;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string kNum = Convert(n, k);
    vector<string> primeArr;
    string tmp;
    for (auto &ch : kNum) {
        if (ch == '0') {
            if (tmp.empty())
                continue;
            primeArr.push_back(tmp);
            tmp.clear();
        } else
            tmp += ch;
    }
    if (!tmp.empty()) // 마지막이 0P인 경우 체크
        primeArr.push_back(tmp);

    for (auto &prime : primeArr)
        if (isPrime(stoll(prime))) // 최대값에서 3진수 변환시 int값을 벗어남
            answer++;
    return answer;
}
