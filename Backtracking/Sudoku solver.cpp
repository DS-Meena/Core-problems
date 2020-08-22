#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 2e5 + 5; 
const int mod = 1e9 + 7;

int n, a;

bool isValid(int board[9][9], int r, int c, int d)
{
    for (int row = 0; row < 9; row++)
        if (board[row][c] == d)
            return false;

    for (int col = 0; col < 9; col++)
        if (board[r][col] == d)
            return false;

    for (int row = (r / 3) * 3; row < (r / 3 + 1) * 3; row++)
        for (int col = (c / 3) * 3; col < (c / 3 + 1) * 3; col++)
            if (board[row][col] == d)
                return false;

    return true;
}

bool solve(int board[9][9]) 
{
   for(int r = 0; r < 9; r++){
       for (int c = 0; c < 9; c++) {
           if (board[r][c] == 0) {
                for (int d = 1; d <= 9; d++) {
                    if (isValid(board, r, c, d)) {
                        board[r][c] = d;
                        if (solve(board)) 
                            return true;
                        board[r][c] = 0;   // undo and keep going
                    }
                } 
                return false;             //backtrack
           }
       }
   } 
   return true; 
}

void test_case()
{
    int board[9][9] = {{3, 1, 6, 5, 7, 8, 4, 9, 2},
                         {5, 2, 9, 1, 3, 4, 7, 6, 8},
                         {4, 8, 7, 6, 2, 9, 5, 3, 1},
                         {2, 6, 3, 0, 1, 5, 9, 8, 7},
                         {9, 7, 4, 8, 6, 0, 1, 2, 5},
                         {8, 5, 1, 7, 9, 2, 6, 4, 3},
                         {1, 3, 8, 0, 4, 7, 2, 0, 6},
                         {6, 9, 2, 3, 5, 1, 8, 7, 4},
                         {7, 4, 5, 0, 8, 6, 3, 1, 0}}; 
    solve(board); 

    for (int r= 0 ; r < 9; r++){
        for (int c= 0; c < 9; c++){
            cout << board[r][c] << " ";
        }
        cout << endl;
    }

    cout << endl;
    return;
}



















void solve()
{
    int t;
    t = 1;
    // cin >> t;
    for (int nr = 1; nr <= t; nr++)
    {
        test_case();
    }
}

int main()
{   
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //synchronize c++ streams with c streams
    ios_base::sync_with_stdio(false);
    //guarentes flushing
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
