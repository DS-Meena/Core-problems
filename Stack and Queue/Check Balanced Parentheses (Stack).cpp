#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

bool isValid(string exp)
{
    stack <char> stk;

    for (int i = 0; i < n; i++)
    {
        if (exp[i] == '[' || exp[i] == '(' || exp[i] == '{')
            stk.push(exp[i]);
        else if (exp[i] == ']' || exp[i] == ')' || exp[i] == '}') 
        {
            if (stk.empty())  
                return false;
            char ch = stk.top();
            stk.pop();
            if (ch == '[' && exp[i] == ']') 
                continue;
            if (ch == '(' && exp[i] == ')') 
                continue;
            if (ch == '{' && exp[i] == '}')
                continue;
            return false;
        }
    }

    if (stk.empty())  
        return true;
    return false;
}

void test_case()
{
    string exp = "[](())";
    n = exp.length();

    if (isValid(exp)) cout << "YES";
    else              cout << "NO";

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
