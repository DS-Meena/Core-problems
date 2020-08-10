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

node* sortedInsert(node* sorted_head, node* new_node)
{
    if (! sorted_head || sorted_head->key >= new_node->key)
    {
        new_node->next = sorted_head;
        return new_node;
    }
    else 
    {
        node* curr = sorted_head;
        while(curr->next && curr->next->key < new_node->key)
            curr = curr->next;
        new_node->next = curr->next;
        curr->next = new_node;
    }
    return sorted_head;
}

node* IsortLL(node* head)
{
    node* curr = head;
    node* sorted_head = NULL;
    while(curr)
    {
        node* currNext = curr->next;
        sorted_head = sortedInsert(sorted_head, curr);
        curr = currNext;
    }

    return sorted_head;
}

void test_case()
{
    node* head = newnode(1);
    head->next = newnode(7);
    head->next->next = newnode(3);
    head->next->next->next = newnode(4); 
    head->next->next->next->next = newnode(2); 

    node* ans = IsortLL(head);
    while(ans) {
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
