#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

bool cmp(const string &str1, const string &str2) {
    if (str1.length() < str2.length()) // 길이로 오름차순 정렬
        return true;
    if (str1.length() == str2.length()) // 같으면 사전순
        if (str1 < str2)
            return true;
    return false;
}

int main() {
    fast_io;
    vector<string> words = {"frodo",  "front", "frost",
                            "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    vector<string> reverseWords = words;
    vector<int> answer;

    for (auto &it : reverseWords)
        reverse(it.begin(), it.end());

    sort(words.begin(), words.end(), cmp);
    sort(reverseWords.begin(), reverseWords.end(), cmp);

    for (int i = 0; i < queries.size(); i++) {
        string str = queries[i];
        int start, end;
        if (str[0] != '?') { // 뒤에서 ?가 시작
            int idx = str.find('?');
            for (int wCard = idx; wCard < str.size(); wCard++)
                str[wCard] = 'a';
            start = lower_bound(words.begin(), words.end(), str, cmp) -
                    words.begin();

            for (int wCard = idx; wCard < str.size(); wCard++)
                str[wCard] = 'z';
            end = upper_bound(words.begin(), words.end(), str, cmp) -
                  words.begin();
        } else { // ?가 앞에서부터 시작
            reverse(str.begin(),
                    str.end()); // 문자열을 뒤집어 ?뒤에서부터 시작하도록 변경
            int idx = str.find('?');
            for (int wCard = idx; wCard < str.size(); wCard++)
                str[wCard] = 'a';
            start = lower_bound(reverseWords.begin(), reverseWords.end(), str,
                                cmp) -
                    reverseWords.begin();

            for (int wCard = idx; wCard < str.size(); wCard++)
                str[wCard] = 'z';
            end = upper_bound(reverseWords.begin(), reverseWords.end(), str,
                              cmp) -
                  reverseWords.begin();
        }
        answer.push_back(end - start);
    }
    for (auto &it : answer)
        cout << it << " ";
    cout << endl;
}