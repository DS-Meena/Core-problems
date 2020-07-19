#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, sum;

int sum0length(int arr[])
{
    unordered_map <int, int> table;
    int maxLen = 0;
    int sum = 0;
    
    for (int i = 0; i < n; i++){
        sum += arr[i];
        if (sum == 0)      // zeros are present in starting
        {
            if (maxLen < i)
               maxLen = i + 1;
        }
        else if (table.find(sum) != table.end())  // in between elements sum is zero if exists
        {
            if (i - table[sum] > maxLen) 
               maxLen = i - table[sum];
        }
        else
            table[sum] = i;          // if not exists
    }  
    return maxLen;
}

void test_case()
{
    int arr[] = {15, -2, 0, -8, 3, 7, 10, 23}; 
    n = 8;
    int ans = sum0length(arr); 
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
