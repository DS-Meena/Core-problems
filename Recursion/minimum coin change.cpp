#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int minCoins(int coins[], int A)
{
    if (A == 0)
       return 0;

    int min_c = INT_MAX; 
    for (int i = 0; i< n; i++)
    { 
        if (coins[i] <= A)
        {
            if (minCoins(coins, A - coins[i]) != INT_MAX)
                min_c = min(min_c, 1 + minCoins(coins, A - coins[i]));
        }
    }
    return min_c;
}

void test_case()
{
    int coins[] = {2, 3, 5, 6};
    int A = 10;

    n = sizeof(coins) / sizeof(coins[0]);
    cout << minCoins(coins, A);

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
