#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

float median(int arr[], int size)
{
    if (size % 2 == 0) 
        return (arr[size / 2] + arr[size / 2 - 1]) / 2;
    else 
        return arr[size / 2];
}

float medianAM(int arr1[], int arr2[], int size)
{
    if (size <= 0)
       return -1;
    if (size == 1) 
        return double(arr1[0] + arr2[0]) / 2;
    if (size == 2) 
        return double(max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2;
    
    float med1 = median(arr1, size);
    float med2 = median(arr2, size);
    if (med1 == med2) 
        return med1;
    else if (med1 < med2)
    {
        if (size % 2 == 0)  
            return medianAM(arr1 + size / 2 - 1, arr2, size - size/2 + 1);
        else 
            return medianAM(arr1 + size / 2, arr2, size - size / 2);
    }
    else 
    {
        if (size % 2 == 0) 
            return medianAM(arr2 + size / 2 - 1, arr1, size - size / 2 + 1);
        else 
            return medianAM(arr2 + size / 2, arr1, size - size / 2);
    }
}

void test_case()
{
    int arr1[] = {1, 12, 15, 26, 38};
    int arr2[] = {2, 13, 17, 30, 45};
    n = sizeof(arr2) / sizeof(arr2[0]);   

    cout << medianAM(arr1, arr2, n);
        
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
