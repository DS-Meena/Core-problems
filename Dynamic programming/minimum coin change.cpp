#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n;

int minCoins(int c[], int A)
{ 
    int coinchange[A + 1];
    coinchange[0] = 0;

    for (int i = 1; i <= A; i++) 
        coinchange[i] = INT_MAX;
    
    for (int i = 1; i <= A; i++)
    {
        for (int j = 0; j < n; j++){
            if (c[j] <= i)
            {
                int curr_min = coinchange[i - c[j]];
                if (curr_min != INT_MAX && curr_min + 1 < coinchange[i]) 
                    coinchange[i] = curr_min + 1;
            }
        }
    }
    return coinchange[A];
}

void test_case()
{
    int arr[] = {2, 3, 5, 6};
    int amount = 10;
    n = sizeof(arr) / sizeof(arr[0]); 

    int ans = minCoins(arr, amount);
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
