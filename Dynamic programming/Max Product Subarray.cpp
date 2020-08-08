#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int maxPSArray(int arr[])
{
    int max_product[n];
    max_product[0] = arr[0];
    int imax = arr[0];    // max ending here
    int imin = arr[0];    // min ending here

    for (int i = 1; i < n; i++) 
    { 
        if (arr[i] < 0) 
            swap(imax, imin);    // change the point of view

        imax = max(arr[i], imax * arr[i]);
        imin = min(arr[i], imin * arr[i]);
        max_product[i] = imax;
    } 
    return *max_element(max_product, max_product + n);
}

void test_case()
{
    int arr[] = {6, -3, -10, 0, 2};
    n = sizeof(arr) / sizeof(arr[0]);
    cout << maxPSArray(arr);

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
