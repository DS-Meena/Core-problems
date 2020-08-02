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
vector<vector<int>> ans;

void ZigZagLT(node* root)
{
    if (root != NULL)
    {  
        queue <node* > Q;
        Q.push(root); 
        bool zigzag = false;

        while(! Q.empty())
        {  
            vector<int> level;
            int size = Q.size();
            for (int i = 0; i< size; i++)
            {
                node* tmp = Q.front();
                Q.pop(); 
                if (zigzag) 
                    level.insert(level.begin(), tmp->key);
                else 
                    level.push_back(tmp->key); 
                
                if (tmp->left) 
                    Q.push(tmp->left);
                if (tmp->right) 
                    Q.push(tmp->right);
            }
            ans.push_back(level);
            zigzag = !zigzag;
        } 
    }
}

void test_case()
{
    node* root = newnode(3);
    root->left = newnode(9);
    root->right = newnode(20);
    root->right->left = newnode(18);
    root->right->right = newnode(7);

    ZigZagLT(root); 

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
