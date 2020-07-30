#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, k;

int minJumps(int arr[])
{
    int minJump[n];
    for (int i = 0; i < n; i++)  
        minJump[i] = INT_MAX; 
    minJump[0] = 0; 
    
    for (int i = 0; i< n; i++)
    { 
        for (int k = 1; k <= arr[i]; k++) 
            jumps[i + k] = min(jumps[i + k], 1 + jumps[i]);
    } 
    return minJump[n - 1];
}

void test_case()
{
    int arr[] = {2, 3, 2, 4, 4};
    n = sizeof(arr) / sizeof(arr[0]);
    int ans = minJumps(arr);
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
