#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n ;

int longestsequence(int arr[])
{
    int pile_top[n], pile_length[n];
    for (int i =0; i < n; i++){
        pile_top[i] = INT_MIN;
        pile_length[i] = 0;
    }

    for (int i =0; i < n; i++){    // counting the greater elements
        for (int j =0; j < n; j++)
        {
            if(pile_top[j] < arr[i])    //place on smaller card
            {
                pile_top[j] = arr[i];
                pile_length[j] += 1;
                break;
            }
        }
    }
    
    int ans = 0;
    for (int i =0; i < n;i++) 
        ans = max(ans, pile_length[i]);
    
    return ans;
}

void test_case()
{
    int arr[] = {10, 2, 5, 3, 7, 101, 18};
    n = sizeof(arr)/sizeof(arr[0]);
    int ans = longestsequence(arr); 
    cout << ans;

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
