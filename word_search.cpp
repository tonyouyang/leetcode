// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool exist(const int i, const int j, const int step,
               vector<vector<char> > &board, string &word,
               vector<vector<bool> > &visited)
    {
        int n = board.size(), m = board[0].size(), l = word.length(), ret = false;

        if (board[i][j] == word[step])
        {
            if (step + 1 == l)
            {
                ret = true;
            }
            else
            {
                int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                visited[i][j] = true;

                for (int d = 0; d < 4 && !ret; ++d)
                {
                    int ni = i + dir[d][0], nj = j + dir[d][1];

                    ret = ret || ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && exist(ni, nj, step + 1, board, word, visited);
                }

                visited[i][j] = false;
            }
        }

        return ret;
    }

    bool exist(vector<vector<char> > &board, string word)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = board.size();
        if (n == 0) return false;
        int m = board[0].size();
        if (m == 0) return false;
        int l = word.length();
        if (l == 0) return false;

        vector<vector<bool> > visited = vector<vector<bool> > (n, vector<bool> (m, false));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (exist(i, j, 0, board, word, visited)) return true;
            }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n, m;
    vector<vector<char> > b;
    string w;
    char c;

    cin >> w;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        vector<char> v;

        for (int j = 0; j < n; ++j)
        {
            cin >> c;
            v.push_back(c);
        }

        b.push_back(v);
    }

    cout << solution.exist(b, w) << endl;

    return 0;
}
