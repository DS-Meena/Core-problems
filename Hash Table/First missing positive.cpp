#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, sum;

int first_positive(int arr[])
{
    unordered_map <int, bool> map;
    for (int i = 0; i < n; i++)  
         map[arr[i]] = true; 

    for (int i = 1; i <= n; i++) 
        if (map[i] != true) 
             return i;
    return -1; 
}

void test_case()
{
    int arr[] = {2, 4, -7, 6, 8, 1, -10, 15};  
    n = 8; 

    int ans = first_positive(arr);
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
