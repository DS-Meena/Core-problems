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

int minDepth(node* root)
{
    if (! root) 
        return 0;
    //if (root->left == NULL && root->right == NULL) 
    //   return 1;
     
    int left_depth = minDepth(root->left);
    int right_depth = minDepth(root->right);
    

    return min(left_depth, right_depth) + 1;
}

void test_case()
{
    node* root = newnode(10);
    root->left = newnode(5);
    root->right = newnode(15);
    root->left->left = newnode(11);
    root->left->right = newnode(6);

    cout << minDepth(root);

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
