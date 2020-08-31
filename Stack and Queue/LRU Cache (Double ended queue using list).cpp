#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

class LRUCache {
    public:
        list <pair< int, int> > ls;                     // FIFO i.e back() points to last i.e, least used
        unordered_map <int, list <pair <int, int> > :: iterator> map;   // key and pointer to this key in ls
        int size;

        LRUCache(int capacity)
        {
            size = capacity;
        } 
        int get(int key)            
        {
            if (map.find(key) == map.end()) 
                return -1;
                                                   // destination, source list, pointer to this key in list
            ls.splice(ls.begin(), ls, map[key]);  // moves to front because recently used
            return map[key]->second;
        }
        void put(int key, int value)     
        {
            if (map.find(key) != map.end())
            {
                ls.splice(ls.begin(), ls, map[key]);  // moves to front because recently used
                map[key]->second = value;
                return;
            }
            if (ls.size() == size)
            {
                auto d_key = ls.back().first;        // removes from last because least recently used
                ls.pop_back();
                map.erase(d_key);
            }
            ls.push_front({key, value});
            map[key] = ls.begin();                // inserting the pointer to this key
        }
};

void test_case()
{
    LRUCache cache(3);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(1, 3);
    cout << cache.get(1) << endl;  
    cache.put(3, 4);
    cache.put(4, 3);
    cout << cache.get(2) << endl;
    cache.put(5, 5);
    cout << cache.get(1) << endl;
    
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
