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

node* mergeSLL(node* a, node* b)
{
    if (! a) return b;
    if (! b) return a;

    node* output = NULL;
    if (a->key < b->key) {    // first iteration outside, for the first node
        output = a;
        a = a->next;
    }
    else {
        output = b;
        b = b->next;
    }

    node* curr = output;
    while(a && b)                 // while both list's nodes exists
    {
        if (a->key < b->key) {   // compare and traverse forward in the smaller one
            curr->next = a;
            a = a->next;
        }
        else {
            curr->next = b;
            b = b->next;
        }
        curr = curr->next;
    }
    if (a) curr->next = a;      // if one list is still remaining to traverse
    if (b) curr->next = b;

    return output;
}

void test_case()
{
    node* a = newnode(2);
    a->next = newnode(3);
    a->next->next = newnode(4);

    node* b = newnode(1);
    b->next = newnode(5);
    b->next->next = newnode(6);

    node* ans = mergeSLL(a, b);
    while(ans){
        cout << ans->key << " ";
        ans = ans->next;
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
