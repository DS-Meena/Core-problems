#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int minCost(int mat[][4], int i, int j)
{
    if (i == m && j == n) 
        return mat[i][j];
    if (i > m || j > n)   // not choose this path
        return INT_MAX;
    
    int x = minCost(mat, i, j + 1);
    int y = minCost(mat, i + 1, j);
    int z = minCost(mat, i+1, j + 1); 
    int minimum = min(x, min(y, z));   
    
    return (mat[i][j] + minimum );
}

void test_case()
{ 
    int mat[][4] = {
        {5, 3, 4, 10},
        {8, 2, 9, 5},
        {10, 0, 6, 8}
    };
    // destination
    m = 1, n = 3;
    
    cout << minCost(mat, 0, 0);

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
