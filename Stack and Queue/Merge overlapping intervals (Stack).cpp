#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

struct interval{
    int start;
    int end;
};

bool comp(interval a, interval b)
{
    return a.start < b.start;
}

void mergeIntervals(interval arr[])
{
    stack <interval> stk;     // stack of type interval
    stk.push(arr[0]);         // push 0th interval

    for (int i = 1; i < m; i++)
    {
        interval top = stk.top();
        interval curr = arr[i];
        if (top.end < curr.start)    // if current do not overlap with top
            stk.push(curr);          // push current
        else 
        {
            stk.pop();              // otherwise
            top.end = max(top.end, curr.end);      // adjust top then push
            stk.push(top);
        }
    }

    while(! stk.empty()){          // remaining intervals in stack are merged intervals
        interval ans = stk.top();
        stk.pop();
        cout << ans.start << " " << ans.end << endl;
    }

    return;
}

void test_case()
{
    interval arr[] = { {1, 5}, {2, 3}, {4, 8}, {9, 10} }; m = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + m, comp);     // sort according to start time
 
    mergeIntervals(arr); 
    
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
