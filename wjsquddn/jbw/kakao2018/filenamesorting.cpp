#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct fileName
{
    string head;
    int number;
    int idx;
};
vector<fileName> v;

bool compare(fileName f1, fileName f2)
{
    if (f1.head == f2.head)
    {
        if (f1.number == f2.number)
        {
            return f1.idx < f2.idx;
        }
        else
        {
            return f1.number < f2.number;
        }
    }
    else
    {
        return f1.head < f2.head;
    }
}
vector<string> solution(vector<string> files)
{
    vector<string> answer;
    for (int i = 0; i < files.size(); i++)
    {
        string s = files[i];
        string head = "";
        string num = "";
        int number;
        int j;
        for (j = 0; j < s.size(); j++)
        {
            if (s[j] >= '0' && s[j] <= '9')
                break;
            head += s[j];
        }
        for (; j < s.size(); j++)
        {
            if (!(s[j] >= '0' && s[j] <= '9'))
                break;
            num += s[j];
        }

        for (char &c : head)
        {
            c = tolower(c);
        }
        number = stoi(num);
        fileName f;
        f.head = head;
        f.number = number;
        f.idx = i;
        v.push_back(f);
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
    {
        v[i].idx;
        answer.push_back(files[v[i].idx]);
    }
    return answer;
}
int main()
{
    vector<string> s = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
    vector<string> answer = solution(s);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}