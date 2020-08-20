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

string longestCP(string arr[], int left, int right)
{
    if (left == right)  
        return arr[left];
    else 
    {
        int mid = left + (right - left) / 2;
        string left_lcp = longestCP(arr, left, mid);
        string right_lcp = longestCP(arr, mid + 1, right);
        
        return common(left_lcp, right_lcp);
    }
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
