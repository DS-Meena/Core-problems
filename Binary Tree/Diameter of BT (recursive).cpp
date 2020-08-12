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

int maxH(node* root)
{
    if (root)
    {
        int left_h = maxH(root->left);
        int right_h = maxH(root->right);

        return 1 + max(left_h, right_h)
    }
    return 0;
}

int maxD(node* root)
{
    if (root == NULL) 
       return 0;
    
    int left_h = maxH(root->left);
    int right_h = maxH(root->right);
    int curr_d = 1 + left_h + right_h; 

    return max(curr_d, max(maxD(root->left), maxD(root->right)));
}

void test_case()
{
    node* root = newnode(5);
    root->left = newnode(3);
    root->right = newnode(9);
    root->left->left = newnode(1);
    root->left->right = newnode(2);
    root->right->right = newnode(10);
    root->right->left = newnode(7);
    root->right->left->left = newnode(6);
    root->right->left->right = newnode(8);

    cout << maxD(root); 

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
