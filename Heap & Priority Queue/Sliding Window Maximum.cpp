#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

vector <int> ans;
void SWMax(int arr[], int k)
{
    priority_queue <int> window; 
    priority_queue <int> to_drop; 

    for (int i = 0; i < k; i++)
        window.push(arr[i]);
    ans.push_back(window.top()); 

    for(int i = k; i < n; i++)
    {  
        if (arr[i - k] == window.top()) 
            window.pop();
        else 
            to_drop.push(arr[i - k]);
        
        while(! to_drop.empty() && to_drop.top() == window.top()) {  // both top matches
            window.pop();
            to_drop.pop();
        }
        window.push(arr[i]);
        ans.push_back(window.top());
    }
}

void test_case()
{
    int arr[] = {9, 8, 6, 4, 3, 1};
    n = sizeof(arr) / sizeof(arr[0]);
    int num = 4;

    SWMax(arr, num);
    for (int i : ans) 
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
