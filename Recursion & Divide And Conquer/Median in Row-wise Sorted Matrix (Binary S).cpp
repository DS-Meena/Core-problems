#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int medianRWSM(int mat[][3])
{
    int lo = INT_MAX;
    int hi = INT_MIN;
    int desired_count = 1 + (m * n) / 2 ;    //no of elements which should be <= to median

    for (int i = 0; i < m; i++)
    {
        lo = min(lo, mat[i][0]);
        hi = max(hi, mat[i][n - 1]);
    }

    while (lo < hi)
    {        
        int mid = lo + (hi - lo) / 2;
        
        int counter = 0;
        for (int i = 0; i < m; i++)
            counter += upper_bound(mat[i], mat[i] + n, mid) - mat[i];   //no of elements in current row which are <= to mid
 
        if (counter < desired_count) 
            lo = mid + 1;
        else 
            hi = mid;
    }

    return lo;
}

void test_case()
{
    int mat[][3] = {
        {2, 3, 3},
        {1, 5, 6},
        {6, 6, 7}
    };
    m = sizeof(mat) / sizeof(mat[0]);   n = sizeof(mat[0]) / sizeof(mat[0][0]);

    cout << medianRWSM(mat);
        
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
