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
    // use extra node to store the starting position of a
        node* head = a;
        node* prev;
        int carry = 0;
        
        // while both exists
        while (a && b)
        {
            // do the arithmetic
            int sum = a->key + b->key + carry;
            
            // a stores the new sum value
            a->key = sum % 10;
            carry = sum / 10 ;
            
            // move forward in both

            prev = a;
            a = a->next;
            b = b->next;
        }
        
        // if a is longer 
         while (a)
        {
            // do the arithmetic
            int sum = a->key + carry;
            
            // store the sum value in b 
            // point a to b
            a->key = sum % 10;
            carry = sum / 10;
            
            // move forward in a
             prev = a;  // for later use
            a = a->next;
        }
        
        // if b is longer 
        while (b)
        {
            // do the arithmetic
            int sum = b->key + carry;
            
            // store the sum value in b 
            // point a to b
            b->key = sum % 10;
            carry = sum / 10;
            prev->next = b;
            
            // move forward in a and b
            prev = b;    // for later use
            b = b->next;
        }
        
        // if carry still exists
        if (carry)
        {
            // create a new node   
            prev->next = newnode(carry);
            
        }
        
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
