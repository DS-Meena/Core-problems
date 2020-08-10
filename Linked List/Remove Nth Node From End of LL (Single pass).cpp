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

node* removeFE(node* head, int k)
{
    node* fast = head;
    node* slow = head;
    
    for (int i = 0; i < k; i++)
    {
        if (fast->next == NULL)    // k <= length of LL
        {
            if (i == k - 1)  
                head = head->next;
            return head;
        }
        fast = fast->next;
    }

    while(fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return head;
}

void test_case()
{
    node* head = newnode(1);
    head->next = newnode(2);
    head->next->next = newnode(3);
    head->next->next->next = newnode(4); 

    node* ans = removeFE(head, 1);
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
