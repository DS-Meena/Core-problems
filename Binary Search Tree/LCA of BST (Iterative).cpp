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
    node* NN = new node;
    NN->key = data;
    NN->left = NULL;
    NN->right = NULL;
    return NN;
}

node* insert(node* root, int data)
{
    if (! root) 
        return newnode(data);
    
    if (data > root->key) 
        root->right = insert(root->right, data);
    else 
        root->left = insert(root->left, data);
    return root;
}

int LCA(node* root, int node1, int node2)
{ 
    node* curr = root;
    while(curr)
    {
        if (node1 > curr->key && node2 > curr->key)       // both greater 
            curr = curr->right;
        else if (node1 < curr->key && node2 < curr->key) // both lesser 
            curr = curr->left;
        else 
            return curr->key;
    } 
    return curr->key;
}

void test_case()
{
    node* root = newnode(5);
    insert(root, 3);
    insert(root, 9);
    insert(root, 1);
    insert(root, 2);
    insert(root, 7);
    insert(root, 10);
    insert(root, 6);
    insert(root, 8);
    
    cout << LCA(root, 2, 8);
 
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
