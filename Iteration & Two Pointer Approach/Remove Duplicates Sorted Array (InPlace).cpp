#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int removeD(int arr[])
{
    if (n <= 1)  
        return n;
    
    int indx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            arr[indx] = arr[i];
            indx++;
        }
    }
    arr[indx] = arr[n - 1];
    indx++;

    return indx;   // no of unqiue elements
}

void test_case()
{
    int arr[] = {2, 3, 3, 4, 5, 7, 7, 9};   n = sizeof(arr) / sizeof(arr[0]);
    cout << removeD(arr);
        
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
