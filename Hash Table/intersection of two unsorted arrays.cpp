#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n = 5, m = 6; 

vector<int> intersection(int arr1[], int arr2[])
{
    vector<int> common; 
    unordered_map <int , int> map1;

    for (int i = 0 ; i < n; i++)   map1[arr1[i]] = 1;
    for (int i = 0; i < m; i++) {
        if (map1[arr2[i]] == 1){
            map1[arr2[i]] = 0;
            common.push_back(arr2[i]);
        }
    } 
    return common;
}

void test_case()
{  
    int arr1[] = {1, 1, 3, 4, 5}, arr2[] = {1, 1, 2, 3, 4, 5}; 

    vector<int> ans = intersection(arr1, arr2); 

    for (int i:ans)  cout << i << " ";
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
