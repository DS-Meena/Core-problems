#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int bounds[2];
void FandLO(int arr[], int target)
{
    int start = 0, end = n - 1;
    while(start < end)                    //first occurance & simple
    {
        int mid = start + (end - start) / 2;
        if (target <= arr[mid]) 
            end = mid;
        else 
            start = mid + 1;
    }  
    bounds[0] = start;
    
    start = start;
    end = n - 1;
    while (start < end)                   //last occurance
    {
        int mid = start + (end - start) / 2 + 1;
        if (target < arr[mid]) 
            end = mid - 1;
        else 
            start = mid;
    }
    bounds[1] = end;
    
    if (arr[bounds[0]] != target) bounds[0] = -1;
    if (arr[bounds[1]] != target) bounds[1] = -1;
    return;
}

void test_case()
{
    int arr[] = {1, 3, 5, 5, 5, 5, 28, 37, 42};   n = sizeof(arr) / sizeof(arr[0]);

    FandLO(arr, 5);
    cout << bounds[0] << " " << bounds[1];
        
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
