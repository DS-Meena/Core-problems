#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int smallestIRSA(int arr[])  //find peak with 3 conditions also works fine
{
    int lo = 0;
    int hi = n - 1;

    while (lo < hi)
    {
        // if array is not rotated or at the drop point
        if (arr[lo] < arr[hi]) 
            return arr[lo];
        
        int mid = lo + (hi - lo)/2;
        
        // if middle is greater than rightmost element i.e, before first peak
        if (arr[mid] > arr[hi]) 
            lo = mid + 1;
        // if middle is smaller than rightmost element i.e, before second peak
        else 
            hi = mid;
    }

    return arr[lo];
}

void test_case()
{
    int arr[] = {4, 5, 6, 2, 4};  n = sizeof(arr) / sizeof(arr[0]);
    cout << smallestIRSA(arr); 
        
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
