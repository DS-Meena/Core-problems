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

struct nodepair{
    node* first;
    node* second;
};

node* mergeBT(node* root1, node* root2)
{
    if (! root1)  return root2;
    if (! root2)  return root1;
    
    stack< nodepair > S; 
    nodepair NP;
    NP.first = root1;
    NP.second = root2;
    S.push(NP);

    while(! S.empty())
    {
        nodepair curr = S.top();
        S.pop();

        if (curr.first == NULL || curr.second == NULL) 
            continue;
        curr.first->key += curr.second->key;    // Process

        if (curr.first->left == NULL)           // left
            curr.first->left = curr.second->left;
        else {
            nodepair tmp;
            tmp.first = curr.first->left;
            tmp.second  = curr.second->left;
            S.push(tmp);
        }  

        if (curr.first->right == NULL)           // right
            curr.first->right = curr.second->right;
        else {
            nodepair tmp;
            tmp.first = curr.first->right;
            tmp.second = curr.second->right;
            S.push(tmp);
        }     
    } 
    return root1;
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
