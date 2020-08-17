#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

void sortWF(int arr[])
{
    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i += 2) 
        swap(arr[i], arr[i + 1]);

    return;
}

void test_case()
{
    int arr[] = {4, 2, 9, 1, 21, 43, 24}; n = sizeof(arr) / sizeof(arr[0]);

    sortWF(arr);
    for (int i = 0; i< n; i++) 
        cout << arr[i] << " ";
        
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
