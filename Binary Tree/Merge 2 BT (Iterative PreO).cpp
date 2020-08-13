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

node* mergeBT(node* a, node* b)
{
    if (! a)  return b;
    if (! b)  return a;
    
    stack <pair <node*, node*> > stk;
    stk.push(make_pair(a, b));

    while(! stk.empty())
    {
        pair <node*, node*> curr = stk.top();
        stk.pop();
        node* first = curr.first;
        node* second = curr.second;

        if (first && second)   
        {
            first->key += second->key;
            if (first->left && second->left)     // both has left child
                stk.push(make_pair(first->left, second->left));
            else if (! first->left) 
                first->left = second->left;
            if (first->right && second->right)   // both has right child
                stk.push(make_pair(first->right, second->right));
            else if (! first->right) 
                first->right = second->right;
        }
    }

    return a;
}

void inOrder(node* root)
{ 
    if (root == NULL) 
       return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
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

    node* ans = mergeBT(root, root2); 
    inOrder(ans);

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
