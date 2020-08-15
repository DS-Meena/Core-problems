#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

stack<int> sort_Stack(stack <int> input)
{
    stack <int> aux;
    while(! input.empty())
    {
        int curr = input.top();
        input.pop();
        while(! aux.empty() && aux.top() < curr)
        {
            input.push(aux.top());
            aux.pop();
        }
        aux.push(curr);
    }

    return aux;
}

void test_case()
{
    int arr[] = {4, 7, 1, 6, 2, 5}; n = sizeof(arr) / sizeof(arr[0]);
    stack <int> input;
    for (int i = 0; i < n; i++) 
        input.push(arr[i]);
    
    stack <int> output = sort_Stack(input);
    while(! output.empty()) {
        cout << output.top() << " ";
        output.pop();
    }
    
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
