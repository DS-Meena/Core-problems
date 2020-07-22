#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n;

bool canPartitioned(int arr[])
{
    int sum = 0;
    for (int i = 0; i < n; i++) 
        sum += arr[i];
    
    if (sum % 2 != 0) 
        return false;
    
    bool sums[sum/ 2 + 1][n + 1]; 
    
    for (int i =0; i <= sum / 2; i++){
        for (int j = 0; j <= n ; j++)
        {
            if (i == 0)    // 0 sum is always possible
                sums[0][i] = true; 
            else if (j == 0)       // not possible with empty set
                sums[i][0] = false;      
            else
            {
                sums[i][j] = sums[i][j - 1];
                if (i >= arr[j - 1])             // sum greater than curr_element
                    if (sums[i][j] || sums[i - arr[j - 1]][j - 1])      //true if lesser sum's cell is true
                        sums[i][j] = true;
            }       
        }
    }
    return sums[sum / 2][n];
}

void test_case()
{
    int arr[] = {1, 6, 11, 6};
    n = sizeof(arr) / sizeof(arr[0]);

    if (canPartitioned(arr)) 
        cout << "YES";
    else 
        cout << "NO"; 

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
