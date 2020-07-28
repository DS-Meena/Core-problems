#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;
string wordDict[] = {"Hard", "Things", "Thing", "About"};

bool dictionaryContains(string word)
{
    m = sizeof(wordDict) / sizeof(wordDict[0]);

    for (int i =0; i < m; i++)
        if (wordDict[i].compare(word) == 0) 
            return true;
    return false;
}

bool canBreaked(string str)
{
    int curr_size = str.length();  // size keeps changing 

    if (curr_size == 0)
        return true;
    
    bool dp[curr_size + 1];    // true if dp[i - 1] can be breaked
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= curr_size; i++)
    {
        if (dictionaryContains(str.substr(0, i)) &&
            dp[i] == false)
            dp[i] = true;

        if (dp[i] == true)   // i th can be breaked
        {
            if (i == curr_size)
                return true;
            for (int j = i + 1; j <= curr_size; j++)  // check sub parts
            {
                if (dp[j] == false && dictionaryContains(str.substr(i, j - i))) 
                    dp[j] = true;
                
                if (j == curr_size && dp[j] == true) 
                    return true;
            }
        }
    }
    return false;
}

void test_case()
{
    string s = "HardThingAboutHardThings";
    if (canBreaked(s))
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
