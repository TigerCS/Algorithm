vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > res;
    vector<string> sol;
    solveNQueensRe(n, 0, 0, 0, sol, res);
    return res;
}

void solveNQueensRe(int n, int row, int ld, int rd, vector<string> &sol, vector<vector<string>> &res)
{
    if (row == (1 << n) - 1)
    {
        res.push_back(sol);
        return;
    }
    int avail = ~(row | ld | rd);
    for (int i = n-1; i >= 0; --i) {
        int pos = 1 << i;
        if (avail & pos) {
            string s(n, '.');
            s[i] = 'Q';
            sol.push_back(s);
            solveNQueensRe(n, row | pos, (ld|pos) << 1, (rd|pos) >> 1, sol, res);
            sol.pop_back();
        }
    }
}
