#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

class MinStack {
    public:
    vector <int> stack;
    vector <int> minArray;
    
    void push(int elem)     //push 
    {
        if (minArray.empty()) 
            minArray.push_back(elem);
        else 
            if (elem <= minArray.back()) 
                minArray.push_back(elem);
        stack.push_back(elem);
    } 
    void pop()             // pop 
    {
        if (stack.back() == minArray.back())  
            minArray.pop_back();
        stack.pop_back();
    }
    int top()             // top 
    {
        if (! stack.empty()) 
            return stack.back();
        else 
            return -1;
    }
    int getMin()           // get min 
    {
        if (! minArray.empty()) 
            return minArray.back();
        else 
            return -1;
    }  
};

void test_case()
{
    MinStack stk;
    stk.push(2);
    stk.push(4);
    cout << stk.top() << " ";
    cout << stk.getMin() << " ";
    stk.pop();
    stk.push(-1);
    cout << stk.getMin() << " ";
    
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
