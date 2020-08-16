#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

void rotateM(int mat[][4])
{
    for (int i = 0; i < m; i++) 
        for (int j = i + 1; j< n; j++) 
            swap(mat[i][j], mat[j][i]);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n / 2; j++) 
            swap(mat[i][j], mat[i][n - 1 - j]);
}

void test_case()
{
    int mat[][4] = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
        };
    m = sizeof(mat) / sizeof(mat[0]);
    n = sizeof(mat[0]) / sizeof(mat[0][0]);

    rotateM(mat);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j< n; j++) 
            cout << mat[i][j] << " ";
        cout << endl;
    } 
  
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
