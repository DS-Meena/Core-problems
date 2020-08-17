#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

void setMZ(int mat[][3])
{
    unordered_map <int, bool> row, col;

    for (int i = 0; i< m; i++) 
        for (int j = 0; j < n; j++) 
            if (mat[i][j] == 0)  {
                row[i] = true;
                col[j] = true;
            }
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) 
            if (row[i] == true || col[j] == true) 
                mat[i][j] = 0;

    return; 
}

void test_case()
{
    int mat[][3] = {
        {1, 0, 1}, 
        {1, 1, 1}, 
        {1, 0, 1}
    };
    m = sizeof(mat) / sizeof(mat[0]); n = sizeof(mat[0]) / sizeof(mat[0][0]);

    setMZ(mat);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) 
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
