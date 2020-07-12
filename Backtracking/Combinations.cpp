#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n = 3, k = 2;

void Possible_comb(vector<int> combination, int no, int size)
{
    if (no > n && size != k)  
        return;
    if (size == k)
    {
        for(int i:combination)  cout << i << " ";
        cout << endl;
        return;
    }
    //including 
    combination.push_back(no);
    Possible_comb(combination, no + 1, size + 1);

    //excluding
    combination.pop_back();
    Possible_comb(combination, no + 1, size);
}

void test_case()
{  
    vector <int > combination;

    Possible_comb(combination, 1, 0);
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
