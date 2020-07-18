#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n ;

void triplet0sum(int arr[])
{
    set<pair<int, pair<int,int>> > mycontainer;  //to remove duplicate triplets
    
    for (int i = 0; i < n -  1; i++) {
        unordered_set <int > sat;
        for (int j = i + 1; j < n; j++) { 

            int dual = -(arr[i] + arr[j]); 

            if (sat.find(x) != sat.end()) {  
                int triplet[] = {arr[i], arr[j], dual};
                sort(triplet, triplet + 3);
                
                pair<int, pair<int,int>> x = make_pair(triplet[0], make_pair(triplet[1], triplet[2]));
                mycontainer.insert(x);
            }
            else 
                sat.insert(arr[j]);
        }
    }
    for (auto i:mycontainer){
        cout << i.first <<" " << i.second.first << " " << i.second.second << endl;
    }
    return;
}

void test_case()
{
    int arr[] = {1, -2, 1, 0, 5};
    n = 5;
    triplet0sum(arr);

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
