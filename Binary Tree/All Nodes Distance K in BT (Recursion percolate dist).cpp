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

node* target;
int k;

void k_Dist_down(node* root, int k)
{
    if (root == NULL || k < 0) return;
    if (k == 0) {
        cout << root->key << " ";
        return;
    }
    k_Dist_down(root->left, k - 1);
    k_Dist_down(root->right, k - 1);
}

int K_Dist_nodes(node* root, int k)
{
    if (root == NULL)  return -1;
    if (root == target) {
        k_Dist_down(root, k);
        return 0;
    } 

    int left_dis = K_Dist_nodes(root->left, k);  //search left
    if (left_dis != -1)
    {
        if (left_dis + 1 == k) 
            cout << root->key << " ";
        else 
            k_Dist_down(root->right, k - left_dis - 2);  // in right subtree with less dist
        return 1 + left_dis;
    } 

    int right_dis = K_Dist_nodes(root->right, k);  //search right
    if (right_dis != -1)
    {
        if (right_dis + 1 == k)
            cout << root->key << " ";
        else 
            k_Dist_down(root->left, k - right_dis - 2);   // in left subtree with less dist
        return 1 + right_dis;
    }
    return -1;
}

void test_case()
{
    node* root = newnode(5);
    root->left = newnode(6);
    root->right = newnode(3);
    root->left->left = newnode(1);
    root->left->right = newnode(7);
    root->left->right->left = newnode(0);
    root->left->right->right = newnode(2);
    root->right->left = newnode(9);
    root->right->right = newnode(4);
    
    target = root->left; k = 2;
    K_Dist_nodes(root, k);

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
