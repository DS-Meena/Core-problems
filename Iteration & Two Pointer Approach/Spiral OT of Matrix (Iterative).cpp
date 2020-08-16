#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

void printSOT(int mat[][4])
{
    int curr_row = 0, curr_col = 0;

    while(curr_row < m && curr_col < n)
    {
        for (int i = curr_col; i < n; i++) 
            cout << mat[curr_row][i] << " ";
        
        curr_row++;
        for (int i = curr_row; i < m; i++) 
            cout << mat[i][n - 1] << " ";
        
        n--;
        if (curr_row < m)
        {
            for (int i = n - 1; i >= curr_col; i--) 
                cout << mat[m - 1][i] << " ";
            m--;
        }
        if (curr_col < n)
        {
            for (int i = m - 1; i >= curr_row; i--)
                cout << mat[i][curr_col] << " ";
            curr_col++;
        }
    }
}

void test_case()
{ 
    int mat[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}, 
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    m = sizeof(mat) / sizeof(mat[0]);  n = sizeof(mat[0]) / sizeof(mat[0][0]);

    printSOT(mat);
  
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
