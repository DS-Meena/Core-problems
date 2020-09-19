#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

struct node{
    int key;
    node* next;
};

node* newnode(int data)
{
    node* NN = new node;
    NN->key = data;
    NN->next = NULL;
    return NN;
}

bool isPalindrome(node** left, node* right)     // &left so that left changes for all recursions
{
    if (right == NULL)
        return true;

    if (! isPalindrome(left, right->next))      // traverse to end
        return false;

    bool ans = (right->key == (*left)->key);   // compare left and right values

    *left = (*left)->next;                     // traverse toward the right

    return ans;
}

void test_case()
{
    node* head = newnode(4);
    head->next = newnode(5);
    head->next->next = newnode(5);
    head->next->next->next = newnode(4);
    head->next->next->next->next = newnode(5);

    if (isPalindrome(&head, head))
        cout << "YES";
    else 
        cout << "NO";

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
