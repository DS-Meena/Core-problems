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

void swap_nodes(node* root)
{
    while (root && root->next)
    {
        swap(root->key, root->next->key);
        root = root->next->next;
    }
}

void test_case()
{
    node* root = newnode(1);
    root->next = newnode(2);
    root->next->next = newnode(3);
    root->next->next->next = newnode(4);

    swap_nodes(root);

    while(root){
        cout << root->key << " ";
        root = root->next;
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
