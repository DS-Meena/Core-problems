#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n = 2; 

bool isequal(int arr1[], int arr2[])
{ 
    unordered_map <int, int > map1;

    for (int i = 0; i < 5; i++)  map1[arr1[i]]++;
    for (int i = 0; i < 5; i++)  map1[arr2[i]]--; 

    for(auto i: map1){ 
        if( i.second != 0) 
            return false;
    }
    return true;
}

void test_case()
{  
    int arr1[] = {1, 2, 5, 2, 1}, arr2[] = {2, 1, 2, 1, 5}; 
    
    if (isequal(arr1, arr2)) 
         cout << 1;
    else 
         cout << 0;

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
