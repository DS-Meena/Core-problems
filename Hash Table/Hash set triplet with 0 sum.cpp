#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n ;

void triplet0sum(int arr[])
{
    for (int i = 0; i < n -  1; i++) {
        unordered_set <int > sat;
        for (int j = i + 1; j < n; j++) { 

            int x = -(arr[i] + arr[j]); 

            if (sat.find(x) != sat.end()) {  

                int tmp[] = {x, arr[i], arr[j]}; 
                sort(tmp, tmp + 3);
                for (int k = 0; k < 3; k++) cout << tmp[k] << " ";
                cout << endl;
            }
            else 
                sat.insert(arr[j]);
        }
    }
}

void test_case()
{
    int arr[] = {1, -2, 1, 0, 5};
    n = 5;
    triplet0sum(arr);

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
