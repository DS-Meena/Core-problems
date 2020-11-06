#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;
vector<string> ans;
#define MAX 26              
#define MAX_WORD_LEN 500

    // Trie Node
    struct node {
        int freq;
        bool end;
        node* child[MAX];  // main
    };
    
    // create a new node 
    node* newnode() 
    {
        node* NTN = new node;
        
        NTN->freq = 0;
        NTN->end = false;
        for (int i = 0; i < MAX; i++)   // main
            NTN->child[i] = NULL;
        
        return NTN;
    }

    // insert a node
    void insert(node* root, string s)
    {
        node* tmp = root;
        int len = s.size();
        
        for (int i = 0; i < len; i++)
        {
            int indx = s[i] - 'a';   
            if (! tmp->child[indx]) 
                tmp->child[indx] = newnode();
            
            tmp = tmp->child[indx];
            tmp->freq++;
        }
        
        tmp->end = true;
    }

    // search string
    string search(node* root, string key)
    {
        string res;
        node* tmp = root;
        
        int len = key.length();
        for (int i = 0; i < len; i++)
        {
            res.push_back(key[i]);
            tmp = tmp->child[key[i] - 'a'];
            if (tmp->freq == 1)
                break;
        }
        
        return res;
    }

void test_case()
{
    vector<string> arr = {"alphabet", "carpet", "cartoon", "carrot", "alpine"};
        // write your awesome code here
        n = arr.size();
        
        // construct a trie of all words
        node* root = newnode();       

        for (int i = 0; i < n; i++)   // insert all strings
            insert(root, arr[i]);
        
        for (int i = 0; i < n; i++)   // search all strings
            ans.push_back(search(root, arr[i]));

    for (string i: ans)
        cout << i << " ";
    
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
