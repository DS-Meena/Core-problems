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

node* add_nodes(node* a, node* b)
{
    node* head = NULL; 
    node* curr = NULL;
    int carry = 0;

    while (a && b)  
    {
        int sum = a->key + b->key + carry;
        carry = sum / 10;
        sum = sum % 10;

        if (curr == NULL){
            curr = newnode(sum);   // create first node
            head = curr;           // make both same
        } 
        else {
            curr->next = newnode(sum);    // first make next node
            curr = curr->next;            // then move it forward
        } 

        a  = a->next;
        b = b->next;
    }
    while(a)
    {
        int sum = a->key + carry;
        carry = sum / 10;
        sum = sum % 10;

        curr->next = newnode(sum);
        curr = curr->next;
        a = a->next;
    }
    while(b)
    {
        int sum = b->key + carry;
        carry = sum / 10;
        sum = sum % 10;

        curr->next = newnode(sum);
        curr = curr->next;
        b = b->next;
    } 
    if (carry != 0)
        curr->next = newnode(carry);
    
    return head;
}

void test_case()
{
    node* A = newnode(1);
    A->next = newnode(8);
    A->next->next = newnode(2);
    node* B = newnode(3);
    B->next = newnode(6);

    node* ans = add_nodes(A, B);

    while(ans){
        cout << ans->key << " ";
        ans = ans->next;
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
