#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;


bool caninterleave(char* a, char* b, char* c)
{
    bool interleave[m + 1][n + 1];
    memset(interleave, 0, sizeof(interleave));

    if ( (m + n) != strlen(c)) 
        return false; 

    for (int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++) 
        {
            if (i == 0 && j == 0)    // 2 empty strings will interleave an empty string
                interleave[i][j] = true;

            else if (i == 0)      // a empty
            {
                if (b[j - 1] == c[j - 1])
                    interleave[i][j] = interleave[i][j - 1];
            }

            else if (j == 0)     // b empty
            {
                if (a[i - 1] == c[i - 1])
                    interleave[i][j] = interleave[i - 1][j];
            }
            // x a[i-1] , y b[j-1], z c[i+j-1]
            
            else if (a[i - 1] == c[i + j - 1] && b[j - 1] != c[i + j - 1])   
                    interleave[i][j] = interleave[i - 1][j]; 

            else if (a[i - 1] != c[i + j - 1] && b[j - 1] == c[i + j - 1]) 
                    interleave[i][j] = interleave[i][j - 1];

            else if (a[i - 1] == c[i + j - 1] && b[j - 1] == c[i + j - 1]) 
                    interleave[i][j] = (interleave[i - 1][j] || interleave[i][j - 1]); 
        }
    }
    return interleave[m][n];
}

void test_case()
{
    char *a = "yx";
    char *b = "x";
    char *c = "yxx"; 
    m = strlen(a);
    n = strlen(b);
    if (caninterleave(a, b, c)) 
        cout << "YES";
    else 
         cout << "NO";

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
