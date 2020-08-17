#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

void moveZTE(int arr[])
{
    int j = 0;
    for (int i = 0; i< n; i++) 
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);   //swap the 0th and non-zero th
            j++;
        }
    }
}

void test_case()
{
    int arr[] = {1, 8, 3, 0, 2, 0, 1, 10, 13, 0};  n = sizeof(arr) / sizeof(arr[0]);
    
    moveZTE(arr);
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
        
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
