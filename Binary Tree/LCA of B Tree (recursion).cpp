#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

struct Node
{
    Node *left, *right;
    int key;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

Node *LCAncestor(Node *root, int node1, int node2)
{ 
    if (root == NULL) 
        return NULL;
    if (root->key == node1 || root->key == node2)
        return root;

    Node *left = LCAncestor(root->left, node1, node2);
    Node *right = LCAncestor(root->right, node1, node2);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
}


void test_case()
{
    Node *root = newNode(5);
    root->left = newNode(6);
    root->right = newNode(3);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(9);
    root->right->right = newNode(4);
    root->left->right->left = newNode(2);
    root->left->right->right = newNode(0);

    Node *ans = LCAncestor(root, 9, 7);
    cout << ans->key;

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
