#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int maxSASum(int arr[])
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < n; i++)
    {
        max_ending_here += arr[i];
        
        max_so_far = max(max_so_far, max_ending_here);
        
        if (max_ending_here < 0) 
            max_ending_here = 0;
    }
    return max_so_far;
}

void test_case()
{
    int arr[] = {-5, 8, 9, -6, 10, -15, 3};
    n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSASum(arr);

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
