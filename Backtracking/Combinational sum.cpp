#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n;
vector<int> arr = {2, 4, 6, 8};

void findNUmbers(int sum, vector<int> combination, int i)
{
    if (sum < 0) 
        return ;
    if (sum == 0)
    {
        for(int j:combination) 
           cout << j << " ";
        cout << endl;
        return;           //backtracking (stop) at the leaf
    }

    if (i < arr.size() && sum - arr[i] >= 0) {
       combination.push_back(arr[i]);
       findNUmbers(sum - arr[i], combination, i); 

       combination.pop_back();     //backtrack to parent node
       findNUmbers(sum, combination, i+1); 
    }
}

void test_case()
{
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    int sum = 16;

    vector<int> combination;
    findNUmbers(sum, combination, 0);   //combination array and current sum
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
