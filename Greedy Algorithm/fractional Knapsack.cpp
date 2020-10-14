#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n ;

struct item
{
    int value;
    int weight;
    float ratio = (float) value / weight;
};

bool comp (item a, item b)
{
    return a.ratio > b.ratio;
}

int maxprofit(item arr[], int capacity)
{
    // sort the items according to their ratio
    sort(arr, arr + n, comp);
    int remCapacity = capacity, currValue = 0, currItem = 0; 
    
    // while remaining capacity is greater than 0
    while (remCapacity > 0)
    {
        // if can take whole item
        if (remCapacity >= arr[currItem].weight)
        {
            currValue += arr[currItem].value;
            remCapacity -= arr[currItem].weight;
            currItem++;
        }

        // if can not take whole item
        else
        {
            currValue += remCapacity * arr[currItem].ratio;
            remCapacity = 0;
        }
    }

    // return total value obtained
    return currValue;
}

void test_case()
{ 
    item arr[] = {{60, 10}, {100, 20}, {120, 30}};   n = sizeof(arr) / sizeof(arr[0]);
    int capacity = 50;
    
    cout << maxprofit(arr, capacity);  

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
