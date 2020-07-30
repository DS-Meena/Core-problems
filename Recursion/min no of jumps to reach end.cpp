#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int minJumps(int arr[], int curr_pos)
{
    if (curr_pos >= n - 1)  //when reach on end, go back 
       return 0;
    
    int minJump = INT_MAX;
    for (int k = 1; k <= arr[curr_pos]; k++)
    {
        minJump = min(minJump, 1 + minJumps(arr, curr_pos + k));   // t(currPos) = n * T(currPos + maxSteps)
    }
    return minJump;
}

void test_case()
{
    int arr[] = {2, 3, 2, 4, 4};
    n = sizeof(arr) / sizeof(arr[0]);
    cout << minJumps(arr, 0);

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
