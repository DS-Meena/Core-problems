#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

float power(int base, int expo)
{
    if (expo == 0) 
        return 1;

    float half_side = power(base, expo / 2); 
    if (expo % 2 == 0) 
        return half_side * half_side;
    else 
    {
        if (expo > 0) 
            return half_side * half_side * base;
        else 
            return half_side * half_side / base;
    }
}

void test_case()
{ 
    k = -7, n = 3;
    cout << power(k, n);
  
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
