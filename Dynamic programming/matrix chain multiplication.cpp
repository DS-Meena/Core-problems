#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n ;

int chainmultiplication(int arr[])
{ 
    int dp[n][n];  

    for (int i =1; i < n; i++)  //single matrix 
        dp[i][i] = 0;
    
    // L is chain length
    for (int L = 2; L < n; L++){
        for (int i = 1; i < n - L + 1; i++)  //starting index
        {
            int j = i + L - 1;   //ending index
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) 
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] +
                                arr[i - 1] * arr[k] * arr[j]);
            }
        }
    }
    return dp[1][n - 1];
}

void test_case()
{ 
    int arr[] = {10, 20, 30, 40, 30};
    n = sizeof(arr) / sizeof(arr[0]);
    int ans = chainmultiplication(arr);
    cout << ans; 

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
