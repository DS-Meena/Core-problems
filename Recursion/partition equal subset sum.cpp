#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n;

bool Checksum(int arr[], int halfsum, int pos)
{ 
    if (halfsum == 0) 
        return true;
    if (halfsum != 0 and pos == 0) 
        return false;

    if(arr[pos - 1] > halfsum) 
    {
        bool excl = Checksum(arr, halfsum, pos - 1);
        return excl;
    } 
    bool incl = Checksum(arr, halfsum - arr[pos - 1], pos - 1);
    bool excl = Checksum(arr, halfsum, pos - 1);

    return incl || excl;
}

bool canPartitioned(int arr[])
{
    int sum = 0;
    for (int i = 0; i < n ; i++) 
        sum += arr[i];
    
    if (sum %2 != 0) 
        return false;
    
    return Checksum(arr, sum / 2 , n);
}

void test_case()
{
    int arr[] = {1, 6, 11, 6};
    n = sizeof(arr) / sizeof(arr[0]);

    if (canPartitioned(arr)) 
        cout << "YES";
    else 
        cout << "NO"; 

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
