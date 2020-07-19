#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n ;

int stairs(int n)
{
    int steps[n + 1];
    steps[0] = 1, steps[1] = 1;

    for (int i = 2; i <= n; i++)
        steps[i] = steps[i - 1] + steps[i - 2];
    
    return steps[n];
}

void test_case()
{ 
    n = 3;
    int ans = stairs(n);
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
