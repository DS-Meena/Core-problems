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

struct compare
{
    bool operator()( node *a,  node *b)
    {
        return a->key > b->key;
    }
};

node* mergeKSL(node* arr[])
{
    priority_queue <node*, vector <node*> , compare > minHeap;
    minHeap.push(arr[0]);
    minHeap.push(arr[1]);
    minHeap.push(arr[2]);

    node* head = NULL;
    node* last;
    while(! minHeap.empty())
    {
        node* curr = minHeap.top();
        minHeap.pop();
        if (curr->next) 
            minHeap.push(curr->next);

        if (head == NULL){
            head = curr;
            last = curr;
        } 
        else {
            last->next = curr;
            last = curr;
        } 
    }
    return head;
}

void test_case()
{
    n = 3;
    node* arr[n];

    arr[0] = newnode(1);
    arr[0]->next = newnode(4); 
    arr[0]->next->next = newnode(5); 
    arr[0]->next->next->next = newnode(7); 

    arr[1] = newnode(0);
    arr[1]->next = newnode(9);
    arr[1]->next->next = newnode(10);

    arr[2] = newnode(2);
    arr[2]->next = newnode(3);
    arr[2]->next->next = newnode(6); 
    arr[2]->next->next->next = newnode(8); 

    node* ans = mergeKSL(arr); 
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
