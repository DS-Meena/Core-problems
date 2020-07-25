#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int match(string s1, string s2, int i, int j, int cache[][100])
{
    if (s1.length() == i)
        return s2.length() - j;
    if (s2.length() == j)
        return s1.length() - i;
    
    if (cache[i][j] != -1)   // if calculated
        return cache[i][j];

    if(s1[i] == s2[j]) 
        cache[i][j] = match(s1, s2, i + 1, j + 1, cache);
    else 
    {
        int insert = match(s1, s2, i, j + 1, cache);
        int delet = match(s1, s2, i + 1, j, cache);
        int substitute = match(s1, s2, i + 1, j + 1, cache);
        cache[i][j] = min(insert, min(delet, substitute)) + 1;   
    } 
    return cache[i][j];
}

int minOperations(string str1, string str2)
{
    int cache[n][100];
    for (int i =0; i < n; i++) 
        for (int j = 0; j < m; j++) 
           cache[i][j] = -1;
    return match(str1, str2, 0, 0, cache);
}

void test_case()
{
    string str1 = "horse", str2 = "ros";
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
