#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n;
int s[3] = {1, 2, 3};

void allSubsets(int pos, int len)
{
    static int subset[3];    
    //or use static vector
    if (pos == 3)
    {   
        cout << " >> ";
        for (int i = 0; i < 3; i++) if (subset[i] != 0) cout << subset[i] << " ";
        cout << endl;
        return ;
    }

    subset[len] = s[pos];
    //include
    allSubsets(pos + 1, len + 1);
    
    //exclude
    subset[len] = 0; 
    allSubsets(pos + 1, len );
}

void test_case()
{  
    allSubsets(0, 0);
     
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
