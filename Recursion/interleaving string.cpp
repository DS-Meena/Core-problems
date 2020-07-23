#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

bool caninterleave(char* a, char* b, char* c)
{
    if (!(*a || *b || *c)) 
        return true;
    if (*c == '\0') 
        return false;

    bool check1 = caninterleave(a + 1, b, c + 1);
    bool check2 = caninterleave(a, b + 1, c + 1);

    return ((*c == *a) && check1) || ((*c == *b) && check2); 
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
