#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;
#define MAX 256
#define MAX_WORD_LEN 500

struct trieNode {    
    int freq;
    trieNode* child[MAX];
};

trieNode* newTrieNode(){
    trieNode* NTN = new trieNode;
    NTN->freq = 1;
    for (int i = 0; i< MAX; i++) 
        NTN->child[i] = NULL;
    return NTN;
}

void insert(trieNode* root, string s)
{
    int len = s.length();
    trieNode* p = root;

    for (int level = 0; level < len; level++)
    {
        int indx = s[level];
        if (! p->child[indx]) 
            p->child[indx] = newTrieNode();
        else 
            p->child[indx]->freq += 1;
        p = p->child[indx];
    }
}

void findPrefixes(trieNode* root, char prefix[], int ind)
{
    if (root == NULL) 
       return;
    
    if (root->freq == 1) 
    {
        prefix[ind] = '\0';
        cout << prefix << " ";
        return;
    }
    for (int i = 0; i< MAX; i++){
        if (root->child[i] != NULL)
        {
            prefix[ind] = i;
            findPrefixes(root->child[i], prefix, ind + 1); 
        }
    }
}

void test_case()
{
    string arr[] = {"alphabet", "carpet", "cartoon", "carrot", "alpine"};
    n = sizeof(arr) / sizeof(arr[0]);

    trieNode* root = newTrieNode();
    root->freq = 0;
    for (int i = 0; i < n; i++)
        insert(root, arr[i]);
    char prefix[MAX_WORD_LEN];
    
    findPrefixes(root, prefix, 0);

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
