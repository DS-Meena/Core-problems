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

void inOrder(node* root)
{
    if (! root) 
        return ; 
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

void recover(node *root, node **first, node **middle, node **last, node **prev)
{
    if (! root)
        return;
        
    recover(root->left, first, middle, last, prev);

    if (*prev && root->key < (*prev)->key)
    {
        if (!*first)
        {
            *first = *prev;
            *middle = root;
        }
        else
            *last = root;
    }
    *prev = root;

    recover(root->right, first, middle, last, prev);
}

void test_case()
{ 
    node* root = newnode(10);
    insert(root, 7); 
    insert(root, 5); 
    insert(root, 9); 
    insert(root, 15); 
    swap(root->left->right, root->right);  
    
    inOrder(root); cout << endl;
    node *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;

    recover(root, &first, &middle, &last, &prev);   // find swapped nodes

    if (first && last)
        swap((first->key), (last->key));
    else
        swap((first->key), (middle->key)); 
    
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
