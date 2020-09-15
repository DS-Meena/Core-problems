#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

void kSmallestPair(int arr1[], int arr2[], int k)
{
    int index2[n];    // which index to consider to arr2
    memset(index2, 0, sizeof(index2));

    while (k > 0)     // untill find k smallest pairs
    {
        int min_sum = INT_MAX;
        int min_indx = 0;

        for (int i = 0; i < m; i++) {      // check each element of arr1 and its corresponding index2[i]th arr2 element
            if (index2[i] < n && arr1[i] + arr2[index2[i]] < min_sum)
            {
                min_indx = i;
                min_sum = arr1[i] + arr2[index2[i]];
            }
        }
        cout << arr1[min_indx] << " " << arr2[index2[min_indx]] << endl;
        index2[min_indx]++;     // already taken 

        k--;
    }
}

void test_case()
{ 
    int arr1[] = {2, 8, 12};  m = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {4, 6, 8};   n = sizeof(arr2) / sizeof(arr2[0]);
    int k = 3;
    kSmallestPair(arr1, arr2, k);
 
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
