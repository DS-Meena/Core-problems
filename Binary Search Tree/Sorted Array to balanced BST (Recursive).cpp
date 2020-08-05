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
};

node* newnode(int data)
{
    node* NN = new node;
    NN->key = data;
    NN->left = NULL;
    NN->right = NULL;
    return NN;
}

void inOrder(node* root)
{
    if (! root) 
        return ;
    
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

node* SAToBST(int arr[], int start, int end)
{
    if (start > end || (start >= n && end >= n)) 
        return NULL;
    
    int mid = start + (end - start) / 2; 
    
    node* root = newnode(arr[mid]);
    root->left = SAToBST(arr, start, mid - 1);
    root->right = SAToBST(arr, mid + 1, end);
    return root;
}

void test_case()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    n = sizeof(arr) / sizeof(arr[0]);

    node* root = SAToBST(arr, 0, n); 
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
