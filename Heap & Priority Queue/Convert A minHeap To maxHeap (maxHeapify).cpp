#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

void maxHeapify(int arr[], int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    
    if (left < n && arr[left] > arr[largest])    // find largest
        largest = left;
    if (right < n && arr[right] > arr[largest]) 
        largest = right;
    
    if (largest != i)    // if parent is not largest
    {
        swap(arr[i], arr[largest]);             // swap parent with largest 
        maxHeapify(arr, largest);              // recurssivley heapify the childs also
    }
}

void test_case()
{
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};  
    n = sizeof(arr) / sizeof(arr[0]);

    for (int i = (n - 2) / 2; i >= 0; i--)   // apply maxHeapify to all nodes except the leaf nodes
        maxHeapify(arr, i);                 // i.e, from (n-2)/2 to 0th node
    
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";

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
