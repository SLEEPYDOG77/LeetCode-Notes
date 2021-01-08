#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // 检查某容器内是否有某数值
    bool hasChar(vector<char>& temp, char i) {
        vector<char>::iterator iter = find(temp.begin(), temp.end(), i);
        if (iter == temp.end()) {
            return false;
        } else {
            return true;
        }
    }

    // 检查每行是否有重复的数
    bool checkRow(vector<char>& row) {
        vector<char> temp;
        temp.clear();
        for (int i = 0; i < 9; i++) {
            if (row[i] != '.') {
                if (hasChar(temp, row[i])) {
                    return false;
                } else {
                    temp.push_back(row[i]);
                }
            }
        }
        return true;
    }

    // 检查每列是否有重复的数
    bool checkColumn(vector<vector<char> >& board, int col) {
        vector<char> temp;
        temp.clear();
        for(int i = 0; i < 9; i++) {
            if (board[i][col] != '.') {
                if (hasChar(temp, board[i][col])) {
                    return false;
                } else {
                    temp.push_back(board[i][col]);
                }
            }
        }
        return true;
    }

    // 检查每个3x3是否有重复的数
    bool checkSub(vector<vector<char> >& board) {

        for (int i = 0; i < 9; i = i +3) {
            for (int j = 0; j < 9; j = j+3) {
                vector<char> temp;
                temp.push_back(board[i][j]);
                temp.push_back(board[i][j+1]);
                temp.push_back(board[i][j+2]);
                
                temp.push_back(board[i+1][j]);
                temp.push_back(board[i+1][j+1]);
                temp.push_back(board[i+1][j+2]);

                temp.push_back(board[i+2][j]);
                temp.push_back(board[i+2][j+1]);
                temp.push_back(board[i+2][j+2]);

                if (!checkRow(temp)) {
                    return false;
                }
            }
        }
        return true;
    }


public:
    bool isValidSudoku_1(vector<vector<char> >& board) {
        // 检查每行
        for (int i = 0; i < 9; i++) {
            if (!checkRow(board[i])) {
                return false;
            }
        }
        // 检查每列
        for (int j = 0; j < 9; j++) {
            if (!checkColumn(board, j)) {
                return false;
            }
        }
        // 检查每个 3x3
        if (!checkSub(board)) {
            return false;
        }
        return true;
    }

    bool isValidSudoku_2(vector<vector<char> >& board) {
        if (board.empty() || board[0].empty()) {
            return false;
        }
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool> > rowFlag(m, vector<bool>(n, false));
        vector<vector<bool> > colFlag(m, vector<bool>(n, false));
        vector<vector<bool> > cellFlag(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; i < n; j++) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int c = board[i][j] - '1';
                    if (rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c]) {
                        return false;
                    }
                    rowFlag[i][c] = true;
                    colFlag[c][j] = true;
                    cellFlag[3 * (i / 3) + j / 3][c] = true;
                }
            }
        }
        return true;
    }
};

int main() {
    // vector<vector<char>> board = {
    //     {'8','3','.','.','7','.','.','.','.'},
    //     {'6','.','.','1','9','5','.','.','.'},
    //     {'.','9','8','.','.','.','.','6','.'},
    //     {'8','.','.','.','6','.','.','.','3'},
    //     {'4','.','.','8','.','3','.','.','1'},
    //     {'7','.','.','.','2','.','.','.','6'},
    //     {'.','6','.','.','.','.','2','8','.'},
    //     {'.','.','.','4','1','9','.','.','5'},
    //     {'.','.','.','.','8','.','.','7','9'},
    // };
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };
    Solution test;
    bool result = test.isValidSudoku(board);
    cout << "result = " << result << endl;
    return 0;
}