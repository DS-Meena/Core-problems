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

void flatten(node* root)
{
    if (root == NULL)
       return;

    stack<node*> S;
    S.push(root);

    while(! S.empty())
    {
        node* tmp = S.top();
        S.pop();

        if (tmp->right) S.push(tmp->right);  // process right
        if (tmp->left)  S.push(tmp->left);    // process left
        
        if (!S.empty())                      // process root
            tmp->right = S.top();
        
        tmp->left = NULL;
    } 
}

void inOrder(node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    } 
    else return;
}


void test_case()
{
    node* root = newnode(1);
    root->left = newnode(3);
    root->right = newnode(4);
    root->right->left = newnode(2);
    root->right->left->right = newnode(5);
    
    inOrder(root); cout << endl;
    flatten(root); 
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
