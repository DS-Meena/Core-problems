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

void mergeBST(node* root1, node* root2)
{ 
    if (! root1) {
        inOrder(root2);
        return;
    }
    if (! root2) {
        inOrder(root1);
        return;
    }
    stack <node* > stk1;
    stack <node* > stk2;
    node* curr1 = root1;
    node* curr2 = root2; 

    while (curr1 || curr2 || !stk1.empty() || !stk2.empty())
    {
        if (curr1 || curr2)  
        {
            if (curr1) {
                stk1.push(curr1);
                curr1 = curr1->left;
            }
            if(curr2) {
                stk2.push(curr2);
                curr2 = curr2->left;
            }
        }
        else 
        {
            if (stk1.empty()) {       //if stack 1 is empty
                while(! stk2.empty())
                {
                    curr2 = stk2.top();
                    stk2.pop();
                    curr2->left = NULL;
                    inOrder(curr2);
                }
                return ;
            }
            if (stk2.empty()) {     // if stack 2 is empty
                while(! stk1.empty())
                {
                    curr1 = stk1.top();
                    stk1.pop();
                    curr1->left = NULL;
                    inOrder(curr1);
                }
                return ;
            } 
            curr1 = stk1.top();
            stk1.pop();
            curr2 = stk2.top();
            stk2.pop(); 

            if (curr1->key < curr2->key)
            {
                cout << curr1->key << " ";
                curr1 = curr1->right;
                stk2.push(curr2);
                curr2 = NULL;
            } 
            else 
            {
                cout << curr2->key << " ";
                curr2 = curr2->right;
                stk2.push(curr1);
                curr1 = NULL;
            } 
        }
    }
    
}

void test_case()
{ 
    node* root1 = newnode(3);
    insert(root1, 4);  
    node* root2 = newnode(6); 
    insert(root2, 2); 
    insert(root2, 10); 
    
    mergeBST(root1, root2);

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
