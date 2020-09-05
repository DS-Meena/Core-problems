#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int merge(int arr[], int tmp[], int start, int mid, int end)
{
    int i = start;         // first half
    int j = mid + 1;      // second half
    int indx = start; 
    int inversion_count = 0;
    while(i <= mid && j <= end)
    {
        if (arr[i] < arr[j])         // add smaller to sorted list
            tmp[indx++] = arr[i++];
        else 
        {
            inversion_count += mid + 1 - i;  //both parts are sorted in themselves
            tmp[indx++] = arr[j++];         //hence other combinations with j also be inverted
        } 
    }

    while(i <= mid) 
        tmp[indx++] = arr[i++];
    while(j <= end) 
        tmp[indx++] = arr[j++];
    for (int i = start; i <= end; i++)
        arr[i] = tmp[i];
    return inversion_count;
}

int mergeSort(int arr[], int tmp[], int start, int end)
{
    int inversion_count = 0;
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        inversion_count += mergeSort(arr, tmp, start, mid);
        inversion_count += mergeSort(arr, tmp, mid + 1, end);
        inversion_count += merge(arr, tmp, start, mid, end);
    }

    return inversion_count;
}

void test_case()
{
    int arr[] = {4, 1, 3, 2};  n = sizeof(arr) / sizeof(arr[0]);

    int tmp[n];
    cout << mergeSort(arr, tmp, 0, n - 1);
        
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
