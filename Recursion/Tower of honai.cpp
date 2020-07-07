#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 2e5 + 5; 
const int mod = 1e9 + 7;

int n;

void towerofHOnai(int n, char frompeg, char topeg, char auxpeg)
{
    if (n == 1) 
    {
        cout << "move topmost wheel from " << frompeg << " to " << topeg << endl; 
        return;
    }  
    towerofHOnai(n - 1, frompeg, auxpeg, topeg);
    towerofHOnai(1, frompeg, topeg, auxpeg);
    towerofHOnai(n-1, auxpeg, topeg, frompeg);

}

void test_case()
{  
    n = 3;
    towerofHOnai(3, 'a', 'c', 'b');
    
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
