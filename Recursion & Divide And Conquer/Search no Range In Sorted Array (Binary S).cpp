#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int lower_bound(int arr[], int low, int high)
{
    while (low < high)
    {
        int mid = (high - low) / 2 + low;
        if (arr[mid] < k) 
            low = mid + 1;
        else 
            high = mid;
    }

    return low;
} 

int upper_bound(int arr[], int low, int high)
{
    while (low < high)
    {
        int mid = (high - low) / 2 + low + 1;
        if (arr[mid] > k) 
            high = mid - 1;
        else 
            low = mid;
    }

    return high;
}

void findrange(int arr[])
{
    int lo = lower_bound(arr, 0, n - 1);
    int hi = upper_bound(arr, 0, n - 1);
    
    if (arr[lo] != k) 
        cout << "-1" << " -1" << endl;
    else 
        cout << lo << " " << hi << endl;
}

void test_case()
{
    int arr[] = {1, 3, 5, 5, 5, 5, 28, 37, 42};   n = sizeof(arr) / sizeof(arr[0]);
    
    k = 5;
    findrange(arr);
        
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
