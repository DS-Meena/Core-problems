#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int findPeak(int arr[], int low, int high) 
{
    while (low < high) 
    {
        int mid = low + (high - low) / 2;   // or check each mid
        
        // check the condition of being peak
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) 
            return mid;
        if (arr[mid] > arr[mid + 1]) 
            high = mid;
        else 
            low = mid + 1;
    } 

    return low;
}

int ascendingBS(int arr[], int low, int high, int k)
{
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) 
            return mid;
        if (arr[mid] > k) 
            high = mid - 1;
        else 
            low = mid + 1;
    }

    return -1;
}

int descendingBS(int arr[], int low, int high, int k)
{
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) 
            return mid;
        if (arr[mid] < k) 
            high = mid - 1;
        else 
            low = mid + 1;
    }
    
    return -1;
}

int findBitonic(int arr[], int k)
{
    int peak = findPeak(arr, 0, n - 1);
    
    if (k > arr[peak]) 
        return -1;
    else if (k == arr[peak])
        return peak;
    else 
    {
        int tmp = ascendingBS(arr, 0, peak - 1, k);
        if (tmp != -1) 
            return tmp;
        
        tmp = descendingBS(arr, peak + 1, n - 1, k);
        if (tmp != -1) 
            return tmp;
    }

    return -1;
}

void test_case()
{ 
    int arr[] = {-3, 8, 9, 20, 17, 5, 1};  n = sizeof(arr) / sizeof(arr[0]);
    k = 17;
    
    cout << findBitonic(arr, k);
        
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
