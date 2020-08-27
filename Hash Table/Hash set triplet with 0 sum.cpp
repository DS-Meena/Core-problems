#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n ;

void triplet0sum(int arr[])
{
    unordered_set <int> present;   //to remove duplicate triplets
    set <pair<int, pair<int, int>> > ans;
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            int sum = -1 * (arr[i] + arr[j]);
            if (present.find(sum) == present.end()) 
                continue;
            
            int tmp[] = {arr[i], arr[j], sum}; 
            sort(tmp, tmp + 3);

            pair<int, pair<int, int>> x = make_pair(tmp[0], make_pair(tmp[1], tmp[2]));
            ans.insert(x);
        }

        present.insert(arr[i]);
    }
    
    for (auto i : ans) 
        cout << i.first << " " << i.second.first <<" " << i.second.second << endl;

    return;
}

void test_case()
{
    int arr[] = {1, -2, 1, 0, 5};
    n = 5;
    triplet0sum(arr);

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
