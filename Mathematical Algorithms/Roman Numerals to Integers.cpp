#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int getValue(char symbol)
{
    if (symbol == 'I') 
        return 1;
    if (symbol == 'V') 
        return 5;
    if (symbol == 'X') 
        return 10;
    if (symbol == 'L') 
        return 50;
    if (symbol == 'C') 
        return 100;
    if (symbol == 'D') 
        return 500;
    if (symbol == 'M') 
        return 1000;
    
    return -1;
}

int romanToInteger(string roman)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int val = getValue(roman[i]);
        if (i + 1 < n)
        {
            int valNext = getValue(roman[i + 1]);
            if (val >= valNext)  
                ans += val;
            else {
                ans += valNext - val;
                i++;
            }
        }
        else 
            ans += val;
    }

    return ans;
}

void test_case()
{ 
    string roman = "MIV";
    n = roman.length();
    cout << romanToInteger(roman);
    
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
