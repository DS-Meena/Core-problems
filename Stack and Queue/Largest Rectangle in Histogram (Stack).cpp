#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int largestHG(int height[])
{
    stack <int> stk;
    stk.push(0);
    int maxArea = 0;

    for (int i = 1; i < n; i++)
    {
        if (height[i] >= height[stk.top()]) 
            stk.push(i);
        else
        {
            while(! stk.empty() && height[stk.top()] > height[i]) 
            {
                int curr = height[stk.top()];
                stk.pop();
                if (stk.empty()) 
                    maxArea = max(maxArea, curr * i);
                else 
                    maxArea = max(maxArea, curr * (i - stk.top() - 1));
            }
            stk.push(i);
        } 
    }
    
    if (! stk.empty())
    {
        while(! stk.empty())
        {
            int curr = height[stk.top()];
            stk.pop();
            if (stk.empty()) 
               maxArea = max(maxArea, curr * n);
            else 
               maxArea = max(maxArea, curr * (n - stk.top() - 1)); 
        }
    }
    
    return maxArea;
}

void test_case()
{
    int arr[] = {2, 4, 8, 10, 8, 4, 2}; n = sizeof(arr) / sizeof(arr[0]);

    cout << largestHG(arr);

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
