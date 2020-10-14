#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int minCandies(int arr[])
{
    int left_candies[n], right_candies[n], total = 0;

    // give one candy to all 
    for (int i = 0; i < n; i++)  {
        left_candies[i] = 1;
        right_candies[i] = 1;
    }
    
    // traverse both arrays in differnt directions
    // give more candy from lower rating child
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i - 1])  
            left_candies[i] = left_candies[i - 1] + 1;
    
    for (int i = n - 2; i >= 0; i--) 
        if (arr[i] > arr[i + 1]) 
            right_candies[i] = right_candies[i + 1] + 1;

    // count total by taking max of both
    for (int i = 0; i < n; i++) 
        total += max(left_candies[i], right_candies[i]);

    return total;
}

void test_case()
{
    int arr[] = {1, 5, 2, 1};   n = sizeof(arr) / sizeof(arr[0]);
    cout << minCandies(arr);

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
