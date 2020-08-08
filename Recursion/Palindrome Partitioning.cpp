#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

bool isPalindrome(string s, int i, int j)   
{
    while(j > i)
    {
        if (s[i] != s[j]) 
            return false;
        i++, j--;
    }
    return true;
}

int minCuts(string s)     /// similar to matrix chain multiplication
{
    int size = s.length();
    if (size == 0 || isPalindrome(s, 0, size - 1))  // for each substring check palindrome
        return 0;
    
    int min_cuts = INT_MAX;
    for (int i = 1; i < size; i++)
    {
        string prefix = s.substr(0, i);
        string suffix = s.substr(i, size - i);

        int cuts = 1 + minCuts(prefix) + minCuts(suffix);
        min_cuts = min(min_cuts, cuts);
    }         
    return min_cuts;
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
