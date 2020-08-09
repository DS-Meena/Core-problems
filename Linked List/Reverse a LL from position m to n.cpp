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
    
    node* restPart = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return restPart;
}

node* reverseMtoN(node* head, int m, int n)
{
    if (m == n)
        return head;
    
    int count = 1;
    node* curr = head;
    node* revPrev = NULL;
    while (count < m){          //find start pointers
        revPrev = curr;
        curr = curr->next;
        count += 1;
    }
    node* revStart = curr;    

    while(count < n) {         //find end pointers
        curr = curr->next;
        count += 1;
    }
    node* revEnd = curr;
    node* revNext = curr->next;
    curr->next = NULL;
    
    node* revPart = reverse(revStart);
    if (revPrev)
    {
        revPrev->next->next = revNext;
        revPrev->next = revPart;
    }
    else 
    {
        if (revNext) 
            head->next = revNext;
        head = revPart;
    }

    cout << revPrev->key << " " << revStart->key << " " << revEnd->key << " " << revNext->key << endl; 
    return head;
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
