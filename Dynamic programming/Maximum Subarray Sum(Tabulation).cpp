#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int maxSASum(int arr[])
{
    int max_ending_here[n];
    max_ending_here[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (max_ending_here[i - 1] < 0)
            max_ending_here[i] = arr[i];
        else 
            max_ending_here[i] = arr[i] + max_ending_here[i - 1];
    }

    for (int i =0; i< n; i++) 
        cout << max_ending_here[i] << " ";
    cout << endl;
    return *max_element(max_ending_here, max_ending_here + n);
}

void test_case()
{
    int arr[] = {-4, -7, -1, 5, -2};
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
