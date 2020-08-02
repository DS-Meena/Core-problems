#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;

struct Node
{
    Node *left, *right;
    int key;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

bool pathExists(Node* root, int sum)
{
    if (root == NULL)
        return (sum == 0);

    else
    {
        bool ans = 0;

        int subSum = sum - root->key;

        if (subSum == 0 && root->left == NULL && root->right == NULL)
            ans = true;

        if (root->left && pathExists(root->left, subSum))
            ans = true;
        if (root->right && pathExists(root->right, subSum))
            ans = true;

        return ans;
    }
}

void test_case()
{
    int sum = 22;

    Node *root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);
    root->left->left = newNode(11);
    root->right->left = newNode(13);
    root->right->right = newNode(4);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(2);
    root->right->right->right = newNode(1);

    if (pathExists(root, sum))
        cout << "YES";
    else 
        cout << "NO"; 

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
