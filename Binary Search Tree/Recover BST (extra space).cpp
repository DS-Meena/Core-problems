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
vector <int> arr;
void inOrder(node* root)
{
    if (! root) 
        return ; 
    inOrder(root->left);
    arr.push_back(root->key); 
    cout << root->key << " ";
    inOrder(root->right);
}

void SandU(node* root, int ele1, int ele2)
{
    if (root == NULL) 
        return;
    SandU(root->left, ele1, ele2);
    if (root->key == ele1)
        root->key = ele2;
    else if (root->key == ele2) 
        root->key = ele1;
    SandU(root->right, ele1, ele2);
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
    vector <int> dupl;
    dupl = arr; 
    sort(dupl.begin(), dupl.end());
    for (int i = 0; i< dupl.size(); i++){
        if (arr[i] != dupl[i]) 
        {
            SandU(root, arr[i], dupl[i]);   // interchanged elements
            break;
        }
    }
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
