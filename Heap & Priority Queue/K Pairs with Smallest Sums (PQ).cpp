#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

void kSmallestPair(int arr1[], int arr2[], int k)
{
    priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    set <pair <int, int>> my_set;

    pq.push(make_pair(arr1[0] + arr2[0], make_pair(0, 0)));
    my_set.insert(make_pair(0, 0));

    for (int count = 1; count <= k; count++) 
    {
        pair<int, pair <int, int> > tmp = pq.top();
        pq.pop();

        int i = tmp.second.first;
        int j = tmp.second.second;

        cout << arr1[i] << " " << arr2[j] << endl;

        int sum = arr1[i + 1] + arr2[j + 1];
        pair <int, int> tmp1 = make_pair(i + 1, j);

        if (my_set.find(tmp1) == my_set.end()){
            pq.push(make_pair(sum, tmp1));
            my_set.insert(tmp1);
        }

        sum = arr1[i] + arr2[j + 1];
        tmp1 = make_pair(i, j + 1);

        if (my_set.find(tmp1) == my_set.end()) {
            pq.push(make_pair(sum, tmp1));
            my_set.insert(tmp1);
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
