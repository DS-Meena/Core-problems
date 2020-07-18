#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n ;

int distribute(int a[])
{ 
    int candy[n];

    // to the valleys
    for (int i = 0; i < n; i++)
        if (a[i - 1] >= a[i] && a[i] <= a[i + 1])
            candy[i] = 1; 
    
    // to the rises
    for (int i = 1; i < n; i++) 
        if (a[i] > a[i-1] && a[i] <= a[i+1]) 
            candy[i] = candy[i-1] + 1;
    
    // to the falls
    for (int i = n-2; i >= 0; i--) 
        if(a[i] <= a[i-1] && a[i] > a[i+1]) 
            candy[i] = candy[i+1] + 1;
    
    // to the peaks
    for (int i = 1; i < n-1 ; i++)
        if (a[i] > a[i-1] && a[i] > a[i+1]) 
            candy[i] = max(candy[i-1], candy[i+1]) + 1;
    
    int total = 0;
    for (int i =0 ; i<n;i++)
       {
            cout << candy[i] << " ";
            total += candy[i];
       }
    return total;
}

void test_case()
{ 
    int arr[] = {1, 5, 2, 1};
    n = sizeof(arr)/ sizeof(arr[0]);
    int ans = distribute(arr);
    cout << ans;

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
