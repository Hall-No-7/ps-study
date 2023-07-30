#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct Page {
    int idx;
    int Basic_Point;
    vector<string> linklist;
    double linkpoint;
    double matchpoint;
};
string word;
map<string, int> pagenumber;
vector<Page> page;
bool compare(Page a, Page b) {
    if (a.matchpoint >= b.matchpoint) {
        if (a.matchpoint == b.matchpoint) {
            if (a.idx < b.idx) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
string upper(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}
string find_url(string str) {
    string target = "<META PROPERTY=\"OG:URL\" CONTENT=\"HTTPS://";
    int idx = str.find(target);
    idx += target.length();
    string url = "";
    while (str[idx] != '\"') url += str[idx++];
    return url;
}
int findword(string str) {
    string tar1 = "<BODY>";
    string tar2 = "/<BODY>";
    int idx1 = str.find(tar1);
    idx1 += tar1.length();
    int idx2 = str.find(tar2);
    str = str.substr(idx1, idx2 - idx1);
    string cur = "";
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i]) == 0) {
            if (cur == word) cnt++;
            cur = "";
        } else
            cur += str[i];
    }
    return cnt;
}
vector<string> findoutlink(string str) {
    vector<string> result;
    string target = "<A HREF=\"HTTPS://";
    int idx = str.find(target);
    while (idx != -1) {
        idx += target.length();
        string cur = "";
        while (str[idx] != '\"') cur += str[idx++];
        result.push_back(cur);
        str = str.substr(idx);
        idx = str.find(target);
    }
    return result;
}
void callinkpoint() {
    for (int i = 0; i < page.size(); i++) {
        vector<string> v = page[i].linklist;
        int size = v.size();
        for (int j = 0; j < v.size(); j++) {
            string str = v[j];
            //
            if (pagenumber[str] == 0) continue;
            int target_idx = pagenumber[str] - 1;
            page[target_idx].linkpoint += ((double)page[i].Basic_Point / double(size));
        }
    }
    for (int i = 0; i < page.size(); i++) {
        page[i].matchpoint = (double)page[i].Basic_Point + (double)page[i].linkpoint;
    }
    sort(page.begin(), page.end(), compare);
}
void Function(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        string str = upper(v[i]);
        string url = find_url(str);
        pagenumber[url] = i + 1;
        int bp = findword(str);
        vector<string> Out_link = findoutlink(str);
        page.push_back({i, bp, Out_link, 0.0, 0.0});
    }
    callinkpoint();
}
int solution(string word, vector<string> pages) {
    int answer = 0;
    word = upper(word);
    Function(pages);
    answer = page[0].idx;
    return answer;
}

int main() {
    string word = "Muzi";
    vector<string> pages = {
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" "
        "content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>",
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  "
        "\n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"};
    cout << solution(word, pages);
    return 0;
}