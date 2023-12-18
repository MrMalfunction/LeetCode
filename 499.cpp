// Problem : 419. Battleships in a Board
// Link : https://leetcode.com/problems/battleships-in-a-board/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int shipCount = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.')
                    continue;
                if (j + 1 < board[i].size() && board[i][j + 1] == 'X') {
                    board[i][j++] = '.';
                    while (j < board[i].size() && board[i][j] == 'X')
                        board[i][j++] = '.';
                    shipCount++;
                } else if (i + 1 < board.size() && board[i + 1][j] == 'X') {
                    int iCopy = i;
                    board[iCopy++][j] = '.';
                    while (iCopy < board.size() && board[iCopy][j] == 'X')
                        board[iCopy++][j] = '.';
                    shipCount++;
                } else if (j + 1 == board[i].size())
                    shipCount++;
                else if (i + 1 == board.size())
                    shipCount++;
                else {
                    shipCount++;
                    board[i][j] = '.';
                }
            }
        }
        cout << shipCount;
        return shipCount;
    }
};

int main() {
    Solution ob;
    vector<vector<char>> nums = {{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
    ob.countBattleships(nums);
    return 0;
}
