#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int lis_ending_here(int arr[], int curr)
{
    if (curr == 0) 
        return 1;
        
    int ans = 1;
    for (int i = curr - 1; i >= 0; i--)   // how many smaller elements are present
        if (arr[i] < arr[curr])
            ans = max(ans, 1 + lis_ending_here(arr, i));
    
    return ans;
}

int LIS(int arr[])
{
    int max_ans = 1;
    for (int i = 0; i< n; i++)    // for all ending points
        max_ans = max(max_ans, lis_ending_here(arr,i));
    
    return max_ans;
}

void test_case()
{
    int arr[] = {3, 10, 2, 1, 20, 5, 21, -2};
    n = sizeof(arr) / sizeof(arr[0]);    

    cout << LIS(arr);

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
