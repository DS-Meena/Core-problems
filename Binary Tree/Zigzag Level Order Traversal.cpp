#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

struct node
{
    node *left, *right;
    int key;
};

node* newnode(int value)
{
    node* NN = new node;
    NN->key = value;
    NN->left = NULL;
    NN->right = NULL;
    return NN; 
}

vector<vector<int>> ans(3);

void ZigZagLT(node* root, int level)
{
    if (root != NULL)
    {   
        if (level % 2 == 0)
            ans[level].push_back(root->key);  
        else 
            ans[level].insert(ans[level].begin(), root->key);  

        ZigZagLT(root->left, level + 1);
        ZigZagLT(root->right, level + 1);
    }
}

void test_case()
{
    node* root = newnode(3);
    root->left = newnode(9);
    root->right = newnode(20);
    root->right->left = newnode(15);
    root->right->right = newnode(7);

    ZigZagLT(root, 0); 

    for (vector<int> i:ans){
        for (int ii: i) 
           cout << ii << " ";
        cout << endl;
    }

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
