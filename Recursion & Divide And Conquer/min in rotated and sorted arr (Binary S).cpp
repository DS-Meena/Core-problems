#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int smallestIRSA(int arr[], int low, int high)  //find peak with 3 conditions also works fine
{
    while (low < high)
    {
        int mid = low + (high - low) / 2; 
        if (arr[mid] > arr[mid + 1])    // move towards the peak
            high = mid;
        else 
            low = mid + 1;
    }

    return arr[low + 1];
}

void test_case()
{
    int arr[] = {4, 5, 6, 2, 4};  n = sizeof(arr) / sizeof(arr[0]);
    cout << smallestIRSA(arr, 0, n - 1); 
        
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
