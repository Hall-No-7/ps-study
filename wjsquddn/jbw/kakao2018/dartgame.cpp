#include <string>
#include <iostream>
using namespace std;

int solution(string dartResult)
{
    int answer = 0;
    int previous = 0;
    int score = 0;

    for (int i = 0; i < dartResult.length(); i++)
    {
        if (dartResult[i] >= 0 && dartResult[i] <= 9)
        {
            previous = score;
            if (dartResult[i + 1] == '0')
            {
                score = 10;
                i++;
            }
            else
            {
                score = dartResult[i] - '0';
            }
        }
        // S D T
        else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T')
        {
            if (dartResult[i] == 'S')
            {
                score = score;
            }
            else if (dartResult[i] == 'D')
            {
                score = (score * score);
            }
            else if (dartResult[i] == 'T')
            {
                score = (score * score * score);
            }
            answer += score;
            if (dartResult[i + 1] == '*')
            {
                answer += score + previous;
            }
            else if (dartResult[i] == '#')
            {
                answer -= score;
            }
        }
    }
    return answer;
}
int main()
{
    cout << solution("1S2D*3T");
    return 0;
}