#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int match(string s1, string s2, int i, int j)
{
    if (s1.length() == i)
        return s2.length() - j;
    if (s2.length() == j)
        return s1.length() - i;
    
    int result;
    if(s1[i] == s2[j]) 
        return match(s1, s2, i + 1, j + 1);
    else 
    {
        int insert = match(s1, s2, i, j + 1);
        int delet = match(s1, s2, i + 1, j);
        int substitute = match(s1, s2, i + 1, j + 1);
        return min(insert, min(delet, substitute)) + 1;   
    } 
    return result;
}

int minOperations(string str1, string str2)
{
    if (n == 0) 
        return m;
    if (m == 0) 
        return n;
    return match(str1, str2, 0, 0);
}

void test_case()
{
    string str1 = "intention", str2 = "execution";
    n = str1.length();
    m = str2.length();
    int ans = minOperations(str1, str2);
    cout << ans;

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
