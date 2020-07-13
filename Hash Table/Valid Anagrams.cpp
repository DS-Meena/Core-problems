#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n = 6; 

int check_anagram(string s1, string s2) 
{
    int a = s1.length();
    int b = s2.length();
    if (a != b) return 0;
    unordered_map < char, int > map;

    for (int i = 0; i < a; i++) map[s1[i]]++;
    for (int i = 0; i < a; i++) map[s2[i]]--; 

    for (auto i:map){
        if (i.second != 0) 
            return 0;
    }
    return 1;
}

void test_case()
{
    string s1 = "mindorks", s2 = "mindrocks";
    int ans = check_anagram(s1, s2); 

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
