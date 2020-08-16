#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int squareRoot(int num)
{
    if (num == 0 || num == 1) 
        return num;
    
    int start = 1, end = num;   //range of possible ans
    int squareRoot = 1;
    
    while(start <= end)
    {
        int mid = (end - start) / 2 + start;
        if (mid*mid == num)
            return mid;

        if (mid*mid < num)
        {
            start = mid + 1;
            squareRoot = mid;
        }
        else 
            end = mid - 1;
    }

    return squareRoot;
}

void test_case()
{ 
    int num = 25;
    cout << squareRoot(num);
  
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
