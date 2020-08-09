#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;
#define MAX 256
#define MAX_WORD_LEN 500

struct node{
    int key;
    node* left;
    node* right; 
    int rightCount;   //additional information
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
    {
        root->right = insert(root->right, data);
        root->rightCount++;   // no of nodes in right subtree
    }
    else 
       root->left = insert(root->left, data);
    return root;
}

int KthLargest(node* root, int k)
{
    if (root == NULL) 
       return -1;
    if (root)
    {
        node* tmp = root;
        while(tmp)
        {
            if (tmp->rightCount == k - 1) 
                return tmp->key;
            else if (tmp->rightCount < k - 1)
            {
                k -= tmp->rightCount + 1;
                tmp = tmp->left;
            }
            else 
                tmp = tmp->right;
        }
    }
    return -1;
    // or recursive reverse inOrder while checking rightcount
    // kthLargest(root->right);
    // if (root->cright == k - 1) 
    //     cout << root->key;  return;
}

void test_case()
{ 
    node* root = newnode(27);
    insert(root, 25); 
    insert(root, 30); 
    insert(root, 22); 
    insert(root, 26); 
    insert(root, 34); 
 
    cout << KthLargest(root, 3);
    
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
