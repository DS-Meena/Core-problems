#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

#define sum_pair pair<int, pair<int, int>>

void kSmallestPair(int arr1[], int arr2[], int k)
{
    priority_queue<sum_pair, vector<sum_pair>, greater<sum_pair>> minheap;
    set<sum_pair> toCheck;

    sum_pair x = make_pair(arra[0] + arrb[0], make_pair(0, 0));

    minheap.push(x);
    toCheck.insert(x); 

    for (int c = 1; c <= k; c++)
    {
        sum_pair x, y;
        x = minheap.top(); minheap.pop();  //exclude old smallest sum pair
        
        int i = x.second.first;
        int j = x.second.second; 

        cout << arra[i] << " " << arrb[j] << endl;

        x = make_pair(arra[i + 1] + arrb[j], make_pair(i + 1, j));
        y = make_pair(arra[i] + arrb[j + 1], make_pair(i, j + 1)); 
        if (toCheck.find(x) == toCheck.end())  // if not present already
        {
            minheap.push(x);
            toCheck.insert(x);
        }
        if (toCheck.find(y) == toCheck.end())
        {
            minheap.push(y);
            toCheck.insert(y);
        }
    }
}

void test_case()
{ 
    int arr1[] = {2, 8, 12};  m = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {1, 4, 6, 8};   n = sizeof(arr2) / sizeof(arr2[0]);
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
