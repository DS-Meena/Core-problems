#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n = 7; 

int majority(int arr[])
{
    unordered_map <int, int > map; 
    for (int i = 0; i < n;i++)   map[arr[i]]++; 

    for (auto i : map) {
        if (i.second > n/2)  
            return i.first;
    } 
    return -1;
}

void test_case()
{
    int arr[] = {20, 30, 40, 50, 20, 60, 10};
    cout << majority(arr); 

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
