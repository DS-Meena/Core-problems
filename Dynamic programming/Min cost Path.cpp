#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int minCost(int mat[][4])
{
    int dp[m][n]; 
    // fill the last cell that is destination
    dp[m - 1][n - 1] = mat[m - 1][n - 1];

    for (int j = n - 2; j >= 0; j--)    // last row , right to left
        dp[m - 1][j] = dp[m - 1][j + 1] + mat[m - 1][j]; 
    for (int i = m - 2; i >= 0; i--)    // last column, bottom to top 
        dp[i][n - 1] = dp[i + 1][n - 1] + mat[i][n - 1];

    for (int i = m - 2; i >= 0; i--)
        for (int j = n - 2; j>= 0; j--) 
            dp[i][j] = min(dp[i+1][j] , min(dp[i][j + 1], dp[i + 1][j + 1])) + mat[i][j];
    
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) 
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[0][0]; 
}

void test_case()
{ 
    int mat[][4] = {
        {5, 3, 4, 10},
        {8, 2, 9, 5},
        {10, 0, 6, 8}
    };
    m = 3, n = 4;   // 1 index destination
    cout << minCost(mat);

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
