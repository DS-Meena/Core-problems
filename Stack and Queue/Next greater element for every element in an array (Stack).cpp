#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

void nextGE(int arr[], int ans[])
{
    stack<int> stk;
    stk.push(0);     // we will contain indexes because order matters

    for (int i = 1; i< n; i++)   // traverse the array
    {
        while(! stk.empty() && arr[stk.top()] < arr[i])    // until the top of stack element is smaller than current element
        {
            ans[stk.top()] = arr[i];                       // set the ans and pop
            stk.pop();
        }
        stk.push(i);                                       // push the current element's index
    }
    
    return;
}

void test_case()
{
    int arr[] = {1, 2, 3, 4, 5}; n = sizeof(arr) / sizeof(arr[0]);
    int ans[n]; for (int i = 0; i < n; i++) ans[i] = -1;
    
    nextGE(arr, ans);
    for (int i:ans) 
        cout << i << " ";
    
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
