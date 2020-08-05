#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int minJumps(int arr[])
{   
    int prev_limit = 0;
    int curr_limit = 0;
    int jumps = 0;
    for (int i = 0; i < n; i++){
        if (i > prev_limit)
        {
            jumps = jumps + 1;
            prev_limit = curr_limit;
        }
        current = max(curr_limit, i + arr[i]);
    }
    return jumps;
}

void test_case()
{
    int arr[] = {2, 3, 2, 4, 4};
    n = sizeof(arr) / sizeof(arr[0]);
    cout << minJumps(arr);

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
