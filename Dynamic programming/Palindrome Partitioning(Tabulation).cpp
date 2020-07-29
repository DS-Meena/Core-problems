#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int minCuts(string s)
{ 
    int cuts[n][n];
    bool palin[n][n];

    for (int i =0; i < n; i++) {
        cuts[i][i] = 0;
        palin[i][i] = true;
    } 
    
    // consider all strings of length 2 to n
    for (int L = 2; L <= n; L++) {    
        for (int i =0; i< n - L + 1; i++) {  //start
            int j = i + L - 1;               //end 

            if (L == 2)    //check palindrome 
                palin[i][j] = (s[i] == s[j]);
            else
                palin[i][j] = (s[i] == s[j]) && palin[i + 1][j - 1]; 
            
            if (palin[i][j] == true)
                cuts[i][j] = 0;
            else 
            {
                cuts[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++) 
                    cuts[i][j] = min(cuts[i][j], cuts[i][k] + cuts[k + 1][j] + 1);
            }
        }
    }
    return cuts[0][n - 1];
}

void test_case()
{
    string s = "geek";
    n = s.length();
    cout << minCuts(s) ;

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
