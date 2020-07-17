#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n,k;

int start_from(int gas[], int cost[])
{
    int start = 0;
    int tank = 0;
    int total_fuel = 0;
    int total_cost = 0;
    
    for (int i =0; i < n; i++)
    {
        tank += (gas[i] - cost[i]);
        
        total_fuel += gas[i];
        total_cost += cost[i]; 
       
        if (tank < 0){
            start++; 
            // total += tank;
            tank = 0;
        }
    }
    if (total_fuel < total_cost) 
        return -1;
    else 
        return start;
}

void test_case()
{
    int gas[] = {1,2,3,4,5};
    int cost[] = {3, 4, 5, 1, 2}; 
    n = 5;
    int ans = start_from(gas, cost);
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
