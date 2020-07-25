#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int minOperations(string str1, string str2)
{
    int matched[n + 2][m + 2];
    for (int i = 0; i <= n; i++) 
        matched[i][0] = i;
    for (int i = 0; i <=m ; i++)
        matched[0][i] = i;
    
    for (int i = 1; i <= n ; i++){    // tabulation -- fill the table one by one
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1]) 
                matched[i][j] = matched[i - 1][j - 1];
            else 
                matched[i][j] = 1 + min(matched[i - 1][j], min(matched[i][j - 1], matched[i - 1][j - 1]));
        }
    } 
    return matched[n][m];
}

void test_case()
{
    string str1 = "dsm", str2 = "msd";
    n = str1.length();
    m = str2.length();
    int ans = minOperations(str1, str2);
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
