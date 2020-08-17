#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int maxJMI(int arr[])
{
    int Lmin[n], Rmax[n];

    Lmin[0] = arr[0];
    for (int i = 1; i < n; i++) 
        Lmin[i] = min(Lmin[i - 1], arr[i]);
    
    Rmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) 
        Rmax[i] = max(Rmax[i + 1], arr[i]);
    
    int i = 0, j = 0, maxDiff = -1;
    while(j < n && i < n)
    {
        if (Lmin[i] < Rmax[j])  //condition satisfy
        {
            maxDiff = max(maxDiff, j - i);
            j++;
        }
        else 
           i++;
    }

    return maxDiff;
}

void test_case()
{
    int arr[] = {5, 2, 3, 5, 4, 6, 7, 8, 19, 0};  n = sizeof(arr) / sizeof(arr[0]);
    cout << maxJMI(arr);
        
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
