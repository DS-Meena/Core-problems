#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;
                                                         // ampersand in both functions also works fine
void sort_Stack_andInsert(stack<int> *input, int data)  // Bottom top approach
{
    if ((*input).empty() || data < (*input).top()) {
        (*input).push(data);
        return;
    }
    int tmp = (*input).top();
    (*input).pop();
    sort_Stack_andInsert(input, data);
    (*input).push(tmp);
}

stack<int> sort_Stack(stack <int> *input)  // Bottom top approach
{
    if (! (*input).empty()) 
    {
        int data = (*input).top();
        (*input).pop();
        sort_Stack(input);
        sort_Stack_andInsert(input, data);
    }
    return *input;
}

void test_case()
{
    int arr[] = {4, 7, 1, 6, 2, 5}; n = sizeof(arr) / sizeof(arr[0]);
    stack <int> input;
    for (int i = 0; i < n; i++) 
        input.push(arr[i]);
    
    stack <int> output = sort_Stack(&input);
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
