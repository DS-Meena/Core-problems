#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int reverseBits(int num)
{
    int ans = 0;
    while(num > 0)
    {
        ans = ans << 1;    // muliply by 2
        if (num & 1 == 1) 
            ans ^= 1;
        
        num = num >> 1;   // divide by 2 
    }
    
    return ans;
}

void test_case()
{ 
    int num = 6;
    cout << reverseBits(num);
    
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
