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
    int indx = 0;

    for (int i = 1; i < m; i++)
    {
        if (arr[indx].end < arr[i].start)    // if the intervals do not overlap
        {
            indx++;                         // increase indx
            arr[indx] = arr[i];             // store current interval i at indx
        }
        else                                 // if intervals overlap then merge i with indx
        {
            arr[indx].end = max(arr[indx].end, arr[i].end);
            arr[indx].start = min(arr[indx].start, arr[i].start);
        }
    }
    
    for (int i = 0;i <= indx; i++)        // merged intervals are upto indx
        cout << arr[i].start << "  " << arr[i].end << endl;

    return;
}

void test_case()
{
    interval arr[] = { {1, 5}, {2, 3}, {4, 8}, {9, 10} }; m = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + m, comp);

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
