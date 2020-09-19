#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

struct node{
    int key;
    node* next;
};

node* newnode(int data)
{
    node* NN = new node;
    NN->key = data;
    NN->next = NULL;
    return NN;
}

node* reverse(node* head)
{
    if (! head || ! head->next)
        return head;
    
    node* restPart = reverse(head->next);  // strat from the last node 
    head->next->next = head;             // next node's next to itself
    head->next = NULL;                   // itself next to NULL
    return restPart;
    
    //or iteratively , changing pointer directions
    // node* curr = head;
    // node *prev = NULL, *next = NULL;
    // while(curr != NULL) 
    // {
    //     next = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = next;
    // }
    // head = prev;
    // return head;
}

node* reverseMtoN(node* head, int m, int n)
{
    if (m == n)
        return head;
    
    node* revPrev = NULL;
    node* revStart = NULL;
    node* revNext = NULL;
    node* revEnd = NULL;

    int indx = 1;
    node* tmp = head;
    while (tmp)     // find the starting and ending end
    {
        if (indx == m - 1) 
            revPrev = tmp;
        else if (indx == m) 
            revStart = tmp;
        else if (indx == n) 
            revEnd = tmp;
        else if (indx == n + 1) 
            revNext = tmp;

        indx++; 
        tmp = tmp->next;
    }

    // make cuts at both ends
    if (revPrev) revPrev->next = NULL;
    if (revEnd)   revEnd->next = NULL;
    
    
    // reverse m to n list
    node* reverse_head = reverse(revStart);
    tmp = reverse_head;
  
    // join the ending cut first, if exists
    if (revNext) 
    {
        while (tmp->next) tmp = tmp->next;
        tmp->next = revNext;
    }
    
    // join the starting end, if exists
    if (revPrev) {
        revPrev->next = reverse_head;
        return head;
    }

    return reverse_head;  // if not exists revPrev
}

void test_case()
{
    node* head = newnode(15);
    head->next = newnode(20);
    head->next->next = newnode(25);
    head->next->next->next = newnode(30);
    head->next->next->next->next = newnode(35);

    m = 2, n = 4;
    head = reverseMtoN(head, m, n);
    while(head){
        cout << head->key << " ";
        head = head->next;
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
