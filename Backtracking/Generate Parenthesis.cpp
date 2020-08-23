#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n;

void printParenthesis(int pos, int n, int open, int close)
{
    static char str[N];

    if (close == n)
    {
        cout << str << endl;
        return;
    }
    if (open > close)
    {
        str[pos] = '}';
        printParenthesis(pos + 1, n, open, close + 1);
    }

    if (open < n)
    {
        str[pos] = '{';         // backtracking as rewriting
        printParenthesis(pos + 1, n, open + 1, close);
    } 
    return;
}

void test_case()
{  
    int n = 3;
    printParenthesis(0, n, 0, 0);
    // or printParenthesis(0, 0, "") also works fine with
    // if (open < n)
    //     printParenthesis(open + 1, close, seq + "(");
    // if (open > close) 
    //     printParenthesis(open, close + 1, seq + ")")
    
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
