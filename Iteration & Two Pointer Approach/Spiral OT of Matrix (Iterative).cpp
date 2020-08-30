#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

void printSOT(int mat[][4])
{
    int SR = 0, ER = n - 1, SC = 0, EC = n - 1;

    while (ER > SR && EC > SC)
    {
        for (int i = SC; i <= EC; i++) 
            cout << mat[SR][i] << " ";
        SR++; 

        for (int i = SR; i <= ER; i++) 
            cout << mat[i][EC] << " ";
        EC--;  

        for (int i = EC; i >= SC; i--) 
            cout << mat[ER][i] << " ";
        ER--;   

        for (int i = ER; i >= SR; i--) 
            cout << mat[i][SC] << " ";
        SC++;   
    }

    return;
}

void test_case()
{ 
    int mat[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}, 
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    m = sizeof(mat) / sizeof(mat[0]);  n = sizeof(mat[0]) / sizeof(mat[0][0]);

    printSOT(mat);
  
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
