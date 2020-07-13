#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n = 6; 

int longestStreak(int arr[])
{
    int longest_streak = 0;
    unordered_map <int, int> map;

    for (int i = 0; i < n; i++)  map[arr[i]] = 1; 

    for (int i = 0; i < n; i++) {
        if (map[arr[i] - 1] != 1){
            int curr_streak = 1;
            int curr_num = arr[i] + 1;
            while(map[curr_num] == 1) 
            {
                curr_num++;
                curr_streak++;
            }
            longest_streak = max(longest_streak, curr_streak);
        }
    } 
    return longest_streak;
}

void test_case()
{
    int arr[] = {0, -2, 3, -1, 2, 1};

    int ans = longestStreak(arr);

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
