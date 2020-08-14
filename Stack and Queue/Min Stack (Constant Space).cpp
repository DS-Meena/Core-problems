#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

class MinStack {
    public:
    vector <ll> stack;
    ll minimum;

    void push(int x)          // push
    {
        ll y = (long)x;
        if (stack.empty()) {
            stack.push_back(y);
            minimum = y;
        }
        else {
            if (y < minimum) 
            {
                stack.push_back(2 * y - minimum);
                minimum = y;
            }
            else 
                stack.push_back(y);
        }
    }
    void pop()               // pop
    {
        if (stack.back() < minimum) {
            minimum = 2 * minimum - stack.back();
            stack.pop_back();
        }
        else 
            stack.pop_back();
    }
    int top()                // top 
    {
        if (! stack.empty()){
            if (stack.back() < minimum) 
                return minimum;
            else 
                return stack.back();
        }
        else 
            return -1;
    }
    int getMin()              // get Min 
    {
        return minimum;
    }
};

void test_case()
{
    MinStack stk;
    stk.push(2);
    stk.push(4);
    cout << stk.top() << endl;
    cout << stk.getMin() << endl;
    stk.pop();
    stk.push(-1);
    cout << stk.getMin() << endl;
    
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
