#include <string>
#include <vector>
#include <iostream>

using namespace std;
int solution(int m, int n, vector<string> board)
{
    int answer = 0;
    vector<vector<bool>> findSquare(m, vector<bool>(n, 0));
    bool flag = false;
    do
    {
        for (int i = 0; i < findSquare.size(); i++)
            fill(findSquare[i].begin(), findSquare[i].end(), false);
        flag = false;

        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (board[i][j] == '0')
                    continue;
                if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 1][j + 1]))
                {
                    findSquare[i][j] = 1;
                    findSquare[i][j + 1] = 1;
                    findSquare[i + 1][j] = 1;
                    findSquare[i + 1][j + 1] = 1;
                    flag = true;
                }
            }
        }
        // cout << "findsquere:\n";
        // for (int i = 0; i < findSquare.size(); i++)
        // {
        //     for (int j = 0; j < findSquare[i].size(); j++)
        //     {
        //         cout << findSquare[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        //-----------없앨 수 있는 것 없애기 -----------------------
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (findSquare[i][j] == true)
                {
                    answer++;
                    board[i][j] = '0';
                }
            }
        }
        // -----------보드출력확인-----------------
        // for (int i = 0; i < board.size(); i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        //-------------------------------------
        // -----------떨어뜨리기 ---------------
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '0')
                {
                    for (int k = i; k > 0; k--)
                    {
                        if (board[k - 1][j] == '0')
                        {
                            break;
                        }
                        board[k][j] = board[k - 1][j];
                        board[k - 1][j] = '0';
                    }
                }
            }
        }
        // for (int i = 0; i < board.size(); i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    } while (flag);

    return answer;
}

int main()
{
    vector<std::string> strVector = {
        "CCBDE", "AAADE", "AAABF", "CCBBF"};
    int m = 4;
    int n = 5;
    // vector<std::string> strVector = {
    //     "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};
    // int m = 6;
    // int n = 6;
    cout << solution(m, n, strVector);
    return 0;
}