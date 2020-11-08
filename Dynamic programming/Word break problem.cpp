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
    int curr_size = str.length();  

    if (curr_size == 0)
        return true;
    
    bool contains[curr_size + 1];                          
    memset(contains, 0, sizeof(contains));

    for (int i = 1; i <= curr_size; i++)
    {
        // if contains prefix
        if (contains[i] == false && dictionaryContains(str.substr(0, i)))   // check prefix if not checked before
        {
            contains[i] = true;
            
            // prefix to end
            if (i == curr_size)  
                return true;
            
            // if contains suffix
            for (int j = i + 1; j <= curr_size; j++)  // check all suffixes
            {
                if (contains[j] == false && dictionaryContains(str.substr(i, j - i))) 
                {
                    contains[j] = true;
                    
                    // suffix to end
                    if (j == curr_size) 
                        return true;
                }
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
