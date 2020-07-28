#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

bool isPalindrome(string s, int i, int j)   
{
    while(i <= j)
    {
        if (s[i] != s[j]) 
            return false;
        i++, j--;
    }
    return true;
}

int minCuts(string s, int i, int j)     /// similar to matrix chain multiplication
{
    if (i == j || isPalindrome(s, i, j))  // for each substring check palindrome
        return 0;
    
    int min_cuts = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int curr_cuts = minCuts(s, i, k) + minCuts(s, k + 1, j) + 1;
        min_cuts = min(min_cuts, curr_cuts);
    }         
    return min_cuts;
}

void test_case()
{
    string s = "geek";
    n = s.length();
    cout << minCuts(s, 0, n - 1) ;

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