#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int maximalSquare(int mat[][5])
{ 
    int dp[m][n]; 

    for (int i = 0; i < m; i++)
        dp[i][0] = mat[i][0];

    for (int j = 0; j < n; j++) 
        dp[0][j] = mat[0][j];
    
    int maxlen = 0; 
    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++)
        {
            if (mat[i][j] == 1) 
                dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1; 
            else 
                dp[i][j] = 0; 
            maxlen = max(maxlen, dp[i][j]);     
        }
    }
    for (int i =0; i < m; i++){
       for (int j = 0; j < n; j++) 
          cout << dp[i][j] << " ";
       cout << endl;
    }
    return maxlen * maxlen;
}

void test_case()
{
    int mat[][5] = {
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 1, 1, 1}
    };
    m = sizeof(mat) / sizeof(mat[0]);
    n = sizeof(mat[0]) / sizeof(mat[0][0]);
    cout << maximalSquare(mat);

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
