#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n ;

int firstUnique(string s)
{
    unordered_map < char, int > map;

    for (int i = 0; i < s.length(); i++){
        map[s[i]]++;
    } 
    for (int i = 0; i < s.length(); i++) {
        if (map[s[i]] == 1) 
            return i;
    }
    return -1;
}

void test_case()
{
    string s = "abacdcd";
    int ii = firstUnique(s); 
    cout << ii ;

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
