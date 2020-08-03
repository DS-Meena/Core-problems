#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

struct node{
    int key;
    node* left;
    node* right;
};

node* newnode(int data)
{
    node* tmp = new node;
    tmp->key = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void inOrder(node* root)
{ 
    if (root == NULL) 
       return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

node* mergeBT(node* root1, node* root2)
{
    if (root1 == NULL) 
        return root2; 
    if (root2 == NULL) 
        return root1; 
    root1->key += root2->key;     // preOrder

    root1->left = mergeBT(root1->left, root2->left);
    root1->right = mergeBT(root1->right, root2->right);

    return root1; 
}

void test_case()
{
    node* root = newnode(5);
    root->left = newnode(2);
    root->right = newnode(3);
    root->right->right = newnode(1);

    node* root2 = newnode(2);
    root2->left = newnode(3);
    root2->left->left = newnode(1);

    mergeBT(root, root2); 
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
