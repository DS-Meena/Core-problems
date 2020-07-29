#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

int maxPO3Numbers(int arr[])
{
    int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;  // store the no we want
    
    for (int i = 0; i< n; i++)
    {
        if (arr[i] < min1){
            min2 = min1;
            min1 = arr[i];
        }
        else if (arr[i] < min2)
           min2 = arr[i];
        
        if (arr[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2){
            max3 = max2;
            max2 = arr[i];
        }
        else if (arr[i] > max3)
            max3 = arr[i];
    }
    return max(min1 * min2 * max1, max3 * max2 * max1);
}

void test_case()
{
    int arr[] = {-5, -7, 4, 2, 1, 9};
    n = sizeof(arr) / sizeof(arr[0]);
    cout << maxPO3Numbers(arr);

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
