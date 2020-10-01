#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

bool isPalindrome(int num)
{
    int digit, rev = 0;
    n = num;
    while(n != 0)
    {
        digit = n % 10;
        rev = (rev * 10) + digit;
        n = n / 10;
    }

    if (rev == num) 
        return true;
    return false;
}

int closestP(int num)
{
    int low = num - 1;
    int high = num + 1;
    
    while(! isPalindrome(low))
        low--;
    while(! isPalindrome(high))
        high++;
    
    if (abs(num - low) <= abs(num - high)) 
        return low;
    return high;
}

void test_case()
{ 
    int num = 99;
    cout << closestP(num);
  
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
