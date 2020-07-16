#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n;

int maxpoints(int arr[][2])
{
    int max_points = 0;
    for (int i = 0; i < n;i++)
    {
        int localmax = 0, overlap = 1, vertical = 1;
        unordered_map <double, int> map;
        for(int j = i + 1; j < n; j++)
        {
            if (arr[i][0] == arr[j][0] && arr[i][1] == arr[j][1])
               overlap++;
            else if(arr[i][0] == arr[j][0]) 
                vertical++;
            else {
                double slope = double(arr[j][1] - arr[i][1]) / (arr[j][0] - arr[i][0]); 
                map[slope]++;
            }
        }
        for (auto  slope : map) 
            localmax = max(slope.second, localmax); 
        max_points = max(vertical, max(localmax + overlap, max_points));  
    }
    return max_points;
}

void test_case()
{
    int arr[][2] = {{1,1}, {3,2}, {5,3}, {4,1}, {2,3}, {1, 4}};
    n = 6;
    int ans = maxpoints(arr);
    cout << ans;

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
