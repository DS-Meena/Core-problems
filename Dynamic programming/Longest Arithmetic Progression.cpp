#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int longestAP(int arr[])
{ 
    int dp[n][n]; 
    int longestAP = 2;
    for (int i = 0; i < n; i++) 
        dp[i][n - 1] = 2;

    for (int j = n - 2; j > 0; j--)
    {
        int i = j - 1;
        int k = j + 1;
        while (i >= 0 && k <= n - 1){
            if (arr[i] + arr[k] < 2 *  arr[j])   // a + c < 2b
                k++;
            else if (arr[i] + arr[k] > 2 * arr[j]){    // a + c > 2b
                dp[i][j] = 2;
                i--;
            }
            else {                                 // a + c = 2b
                dp[i][j] = dp[j][k] + 1;
                longestAP = max(longestAP, dp[i][j]);
                i--;
                k++;
            }
        }
        while (i >= 0) {
            dp[i][j] = 2;
            i--;
        }
    } 
    return longestAP;
}

void test_case()
{
    int arr[] = {3, 6, 8, 9};
    n = sizeof(arr); 
    cout << longestAP(arr);

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
