#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int minMultiplications(int chain[], int i, int j)
{  
    if (i == j) 
        return 0;

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost = minMultiplications(chain, i, k) + minMultiplications(chain, k + 1, j) + chain[i - 1] * chain[k] * chain[j]; 
        ans = min(ans, cost);
    }
    return ans;
}

void test_case()
{
    int chain[] = {10, 20, 30};
    n = sizeof(chain) / sizeof(chain[0]);

    cout << minMultiplications(chain, 1, n - 1); 

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
