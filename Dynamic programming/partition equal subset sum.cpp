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
        for (int i = 0; i< n; i++)
            sum += arr[i];
        
        if (sum % 2 != 0)
            return false;
        
        // create a sum array
        bool cando[sum / 2 + 1][n + 1];
        
        // initialization 
        // 0 elements not possible
        for (int i = 0; i <= sum / 2; i++)
            cando[i][0] = false;
        
        // 0 sum always possible
        for (int i = 0; i <= n; i++)
            cando[0][i] = true;
        
        for (int s = 1; s <= sum / 2; s++)
        {
            for (int j = 1; j <= n; j++)
            {
                cando[s][j] = cando[s][j - 1];
                if (s >= arr[j - 1])    // sum greater than current element
                    if (cando[s][j] || cando[s - arr[j - 1]][j - 1])   // true if lessers sum's cell is true
                        cando[s][j] = true;
            }
        }
        
        return cando[sum/2][n];
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
