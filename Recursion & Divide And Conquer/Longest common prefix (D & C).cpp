#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

string common(string a, string b)
{
    int smaller = min(a.length(), b.length());
    for (int i = 0; i < smaller; i++)
    {
        if (a[i] != b[i])  
            return a.substr(0, i);
    }

    return a.substr(0, smaller);
}

string longestCP(string arr[], int start, int end)
{
    // if problem is small like one word
    if (start == end)
        return arr[start];

    // divide problem into two subproblems 
    int mid = start + (end - start) / 2;
    string ans1 = longestCP(arr, start, mid);
    string ans2 = longestCP(arr, mid + 1, end);
    
    // combine the results
    return common(ans1, ans2);
}

string LCPdriver(string arr[], int size)
{
    if (size == 0) 
        return "-1";
    return longestCP(arr, 0, size - 1);
}

void test_case()
{
    string arr[] = {"flower","flow","floght"};   n = sizeof(arr) / sizeof(arr[0]);
    
    string ans = LCPdriver(arr, n);
    if (ans.length()) 
         cout << ans;
    else 
         cout << "-1";
        
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
