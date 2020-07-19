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
    double ratio;
};

bool comp (item a, item b)
{
    return a.ratio > b.ratio;
}

int maxprofit(int items[][2], int capacity)
{
    item arr[n];
    for (int i =0; i < n;i++){
        arr[i].value = items[i][0];
        arr[i].weight = items[i][1];
        arr[i].ratio = double(items[i][0]/items[i][1]);
    } 
    sort(arr, arr+n, comp); 
    
    double totalValue = 0.0;
    int currUsedWeight = 0;
    for (int i =0; i < n; i++){
        if (currUsedWeight +  arr[i].weight <= capacity)
        {
            totalValue += arr[i].value;
            currUsedWeight += arr[i].weight; 
        }
        else
        { 
            int availableSpace = capacity - currUsedWeight; 
            // taking the fraction
            totalValue += arr[i].value*((double)availableSpace/arr[i].weight);
            break;
        }
    }

    return totalValue;
}

void test_case()
{ 
    int items[][2] = {{60, 10}, {100, 20}, {120, 30}};
    n = sizeof(items)/sizeof(items[0]);
    int capacity = 50; 
    int ans = maxprofit(items, capacity);
    cout << ans; 

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
