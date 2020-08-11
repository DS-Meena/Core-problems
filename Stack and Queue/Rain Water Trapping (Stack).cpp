#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int trappedWater(int height[])
{
    stack <int> stk;
    int maxWater = 0;

    for (int curr = 0; curr< n; curr++)
    {
        while(! stk.empty() && height[curr] > height[stk.top()])
        {
            int top = stk.top();
            stk.pop();
            
            if (stk.empty()) 
                break;
            
            int distance = curr - stk.top() - 1;
            int bounded_height = min(height[curr], height[stk.top()]) - height[top];
            maxWater += distance * bounded_height;
        }
        stk.push(curr);
    }

    return maxWater;
}

void test_case()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 1, 1};  n = sizeof(arr) / sizeof(arr[0]);

    cout << trappedWater(arr);

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
