#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int trappedWater(int height[])
{
    int maxWater = 0;
    int left_mh[n], right_mh[n];

    left_mh[0] = height[0];        // stores maximum height on left side of i
    for (int i = 1; i < n; i++) 
        left_mh[i] = max(height[i], left_mh[i - 1]);

    right_mh[n - 1] = height[n - 1];    // stores maximum height on right side of i
    for (int i = n - 2; i >= 0; i--) 
        right_mh[i] = max(height[i], right_mh[i + 1]);

    for (int i = 1; i < n; i++)         // for each bar calculate water stored
        maxWater += min(left_mh[i], right_mh[i]) - height[i];
    
    return maxWater;
}

void test_case()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};  n = sizeof(arr) / sizeof(arr[0]);

    cout << trappedWater(arr);

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
