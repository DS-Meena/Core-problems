#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

struct node
{
    node *left, *right;
    int key;
};

node* newnode(int value)
{
    node* NN = new node;
    NN->key = value;
    NN->left = NULL;
    NN->right = NULL;
    return NN; 
}

void invertBT(node* root)
{
    if (root == NULL) 
       return;
    
    swap(root->left, root->right);

    invertBT(root->left);
    invertBT(root->right);
}

void inOrder(node* root)
{
    if(root == NULL) 
       return;
    
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right); 
}

void test_case()
{
    node* root = newnode(3);
    root->left = newnode(9);
    root->right = newnode(20);
    root->right->left = newnode(15);
    root->right->right = newnode(7);
    
    inOrder(root);cout<<endl;
    invertBT(root);
    inOrder(root);

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
