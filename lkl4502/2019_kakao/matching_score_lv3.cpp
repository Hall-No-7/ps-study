#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
using namespace std;

struct WebPage {
    int idx;
    float basicScore = 0, linkScore = 0;
    vector<string> linkPage;
};

int main() {
    fast_io;
    string word = "muzi";
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    vector<string> pages = {
        " < html lang =\"ko\" xml:lang=\"ko\" "
        "xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  "
        "<meta charset=\"utf-8\">\n  <meta property=\"og:url\" "
        "content=\"https://careers.kakao.com/interview/list\"/"
        ">\n</head>  \n<body>\n<a "
        "href=\"https://programmers.co.kr/learn/courses/"
        "4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>",
        "<html lang=\"ko\" xml:lang=\"ko\" "
        "xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta "
        "charset=\"utf-8\">\n  <meta property=\"og:url\" "
        "content=\"https://www.kakaocorp.com\"/>\n</head>  "
        "\n<body>\ncon%\tmuzI92apeach&2<a "
        "href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"};

    map<string, int> idxList;
    vector<WebPage> pageList;

    for (int i = 0; i < pages.size(); i++) {
        transform(pages[i].begin(), pages[i].end(),
                  pages[i].begin(), // 소문자로 변환
                  ::tolower);
        WebPage web;
        string urlHeader = "<meta property=\"og:url\" "
                           "content=\"";
        auto start = pages[i].find(urlHeader);
        auto end = pages[i].find("\"/>", start);
        idxList[pages[i].substr(start + urlHeader.length(), // webPage의 url
                                end - start - urlHeader.length())] = i;
        pageList.push_back(web);
    }

    for (int i = 0; i < pages.size(); i++) {
        auto it = pages[i].find(word);
        int count = 0;

        while (it != string::npos) { // 기본점수 측정
            if (!isalpha(pages[i][it - 1]) &&
                !isalpha(pages[i][it + word.length()]))
                count++;
            it = pages[i].find(word, it + word.length());
        }

        pageList[i].idx = i;            // 페이지 인덱스 저장
        pageList[i].basicScore = count; // 기본점수 할당

        string linkHeader = "<a href=\"";
        auto start = pages[i].find(linkHeader);
        while (start != string::npos) { // 링크된 페이지 url 저장
            auto end = pages[i].find("\">", start);
            pageList[i].linkPage.push_back(
                pages[i].substr(start + linkHeader.length(),
                                end - start - linkHeader.length()));
            start = pages[i].find(linkHeader, end);
        }

        for (auto &it : pageList[i].linkPage) {
            if (idxList.find(it) == idxList.end())
                continue;
            pageList[idxList[it]].linkScore +=
                (pageList[i].basicScore / pageList[i].linkPage.size());
        }
    }

    float highest = 0;
    int answer = 0;

    for (auto &it : pageList) {
        float sum = it.basicScore + it.linkScore;
        if (highest < sum) {
            answer = it.idx;
            highest = sum;
        }
    }

    cout << answer << endl;
}