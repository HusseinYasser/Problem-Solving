#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    void backtrack(int i, int j, int n, string currRow, vector<string>board, vector<vector<string>>& ans, vector<bool>rows, vector<bool>columns, vector<pair<int,int>>pos, int queens)
    {
        if(j == n)
        {
            if(queens != i+1)
                return;
            board.push_back(currRow);
            backtrack(i+1, 0, n, "", board, ans, rows, columns, pos, queens);
            return;
        }
        if(i == n)
        {
            if(queens == n)
                ans.push_back(board);
            return;
        }
        //try to put the queen here anc if not possible don't put it
        bool isRowAvailable = !rows[i], isAvailableColumns = !columns[j];
        bool isDiagonal = 1;
        for(auto pp : pos)
        {
            if(abs(pp.first - i) == abs(pp.second - j))
            {
                isDiagonal = 0;
                break;
            }
        }
        if(isRowAvailable && isAvailableColumns && isDiagonal)
        {
            currRow.push_back('Q');
            rows[i] = 1;
            columns[j] = 1;
            pos.push_back({i, j});
            backtrack(i, j+1, n, currRow, board, ans,rows, columns, pos, queens+1);
            pos.pop_back();
            rows[i] = 0;
            columns[j] = 0;
            currRow.pop_back();
        }
        currRow.push_back('.');
        backtrack(i, j+1, n, currRow, board, ans, rows, columns, pos, queens);
        currRow.pop_back();
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<bool> rows(n, 0), columns(n, 0);
        vector<vector<string>>res;
        vector<string>currRow;
        vector<pair<int,int>>pos;
        backtrack(0, 0, n, "", currRow, res, rows, columns, pos, 0);
        return res;
    }
};