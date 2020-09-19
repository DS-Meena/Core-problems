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

void DARLoop(node* head)
{
    if (! head || ! head->next)     
        return;

    node *slow = head, *fast = head;          // initialize slow and fast as head

    slow = slow->next;                        // do first iteration outside, for equal condition
    fast = fast->next->next;
    
    while(fast && fast->next && slow != fast)     // while slow != fast and fast, fast->next exists
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->key << " " << fast->key << endl;

    if (slow == fast)   // if loop exists
    {
        slow = head;                                // set slow as head
        while (slow->next != fast->next){           // until next of slow and fast becomes same
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;                           // make next of fast as NULL
    }
    return;
}

void test_case()
{
    node* head = newnode(1);
    head->next = newnode(2);
    head->next->next = newnode(3);
    head->next->next->next = newnode(4);
    head->next->next->next->next = newnode(5);
    head->next->next->next->next->next = head->next;

    DARLoop(head);
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
