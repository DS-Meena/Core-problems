#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n ;

int longestsequence(int arr[])
{
    int lis[n];
    for (int i = 0; i < n; i++) 
       lis[i] = 1;
    lis[0] = 1;

    for (int i = 0; i < n; i++){   // fix ending point
        for (int j = 0; j < i ; j++) 
        {
            if (arr[j] < arr[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }  
    
    int ans = 1;
    for (int i = 0; i < n; i++)  
        ans = max(ans, lis[i]);
    return ans;
}

void test_case()
{
    int arr[] = {3, 10, 2, 1, 20};
    n = sizeof(arr)/sizeof(arr[0]);
    int ans = longestsequence(arr); 
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
