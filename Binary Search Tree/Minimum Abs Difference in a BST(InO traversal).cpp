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

vector <int> ans;
void inOrder(node* root)
{
    if (! root) 
        return ; 
    inOrder(root->left);
    ans.push_back(root->key);
    inOrder(root->right);
}

void test_case()
{ 
    node* root = newnode(7);
    insert(root, 3); 
    insert(root, 2); 
    insert(root, 5); 
    insert(root, 10); 
    insert(root, 8); 
    insert(root, 12); 
 
    inOrder(root);

    int min_diff = INT_MAX;
    for (int i = 1; i< ans.size(); i++){
        int curr_diff = ans[i] - ans[i - 1];
        min_diff = min(min_diff, curr_diff);
    }
    cout << min_diff;
 
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
