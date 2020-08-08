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

bool isPalindrome(node* head)
{
    if (! head || ! head->next) 
        return true;
    
    stack < int > stk;
    node* tmp = head;

    while(tmp){                    // bottom to top
        stk.push(tmp->key);
        tmp = tmp->next;
    }

    tmp = head;
    while(tmp){                    // top to bottom
        if (tmp->key != stk.top())
            return false;
        stk.pop();
        tmp = tmp->next;
    }

    return true;
}

void test_case()
{
    node* head = newnode(4);
    head->next = newnode(5);
    head->next->next = newnode(5);
    head->next->next->next = newnode(4);
    
    if (isPalindrome(head))
        cout << "YES";
    else 
        cout << "NO";

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
