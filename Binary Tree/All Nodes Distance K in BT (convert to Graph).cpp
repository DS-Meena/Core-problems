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

unordered_map<int, vector<int>> graph;
vector<int> ans;

void buildGraph(node* root, node* parent)
{
    if (!root)
       return;
    
    if (! graph.count(root->key))  // if not present
    {
        if (parent){
            graph[root->key].push_back(parent->key);  // add neighbours
            graph[parent->key].push_back(root->key);
        }
        buildGraph(root->left, root);
        buildGraph(root->right, root);
    }
}

void bfs(int target, int k)  // level order
{
    queue<int > q;
    unordered_map<int, bool> visited;

    int depth = 0; 
    if (k == 0){
        ans.push_back(target);
        return;
    }
    
    q.push(target);
    while(! q.empty())
    {
        depth += 1;
        int q_size = q.size();
        for (int i = 0; i< q_size; i++)    // all nodes on the same level
        {
            int curr_node = q.front();
            visited[curr_node] = true; 
            q.pop();

            for (int neighbour : graph[curr_node])   // for all neighbours
            {
                if (! visited.count(neighbour)) {     // if not visited
                    if (depth == k)  
                        ans.push_back(neighbour);
                    else 
                        q.push(neighbour);
                }
            }
        }
        if (depth == k) 
           return;
    }
}

void test_case()
{
    node* root = newnode(5);
    root->left = newnode(6);
    root->right = newnode(3);
    root->left->left = newnode(1);
    root->left->right = newnode(7);
    root->left->right->left = newnode(0);
    root->left->right->right = newnode(2);
    root->right->left = newnode(9);
    root->right->right = newnode(4);

    buildGraph(root, nullptr);
    
    int k = 2;
    bfs(6, k);

    for(int i:ans) 
        cout << i << " ";
    cout <<endl; 

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
