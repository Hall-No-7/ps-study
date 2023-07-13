#include <bits/stdc++.h>
#define ENDL "\n"
using namespace std;

struct File {
    int idx;
    string head = "";
    int number;
};

bool cmp(const File &f1, const File &f2) {
    if (f1.head == f2.head) {
        if (f1.number == f2.number)
            return f1.idx < f2.idx;
        else
            return f1.number < f2.number;
    } else
        return f1.head < f2.head;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> files;
    files.push_back("img12.png");
    files.push_back("img10.png");
    files.push_back("img0.png");
    files.push_back("img02000000.png");
    files.push_back("img1.png");
    files.push_back("IMG01.GIF");
    files.push_back("img2.JPG");

    vector<string> answer;
    vector<File> arr;

    for (int i = 0; i < files.size(); i++) {
        string str = "", number = "";
        bool flag = false;
        File file;
        file.idx = i;
        int maxNumberIdx = 0;
        for (int j = 0; j < files[i].size(); j++) {
            str += tolower(files[i][j]);
            if (!isdigit(str[j]) && !flag)
                file.head += str[j];
            else if (isdigit(str[j]) && maxNumberIdx < 5) {
                maxNumberIdx++;
                number += str[j];
                flag = true;
            } else
                break; // continue가 아닌 이유는 maxNumberIdx가 5보다 작을 때
                       // Number가 끝이 나면 다시 Number를 채우는 경우가 있다.
        }
        file.number = stoi(number);
        arr.push_back(file);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < arr.size(); i++)
        answer.push_back(files[arr[i].idx]);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ENDL;
    }
}