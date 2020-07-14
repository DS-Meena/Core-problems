#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n ;

struct elem 
{
    char ch;
    int freq;
    int first_index;
};

bool comp(elem a, elem b)
{
    if (a.freq != b.freq) 
        return a.freq > b.freq;   // higher freq comes first
    else
        return a.first_index < b.first_index;  // lower index comes first
}

void sortbyFrequency(string s)
{
    unordered_map <char , int> count, index;
    
    for (int i = 0; i < n; i++) {
        if (count[s[i]] == 0) {
            count[s[i]] = 1;
            index[s[i]] = i;
        }
        else {
            count[s[i]]++;
        }
    }
    elem freq_arr[n];
    int j = 0;
    for (auto i : count){ 
        freq_arr[j].ch = i.first;
        freq_arr[j].freq = i.second; 
        freq_arr[j].first_index = index[i.first]; 
        
        j++;
    } 
    

    sort(freq_arr, freq_arr + j, comp); 
    for (int i = 0; i < j ;i++){ 
        for (int j = 0; j < freq_arr[i].freq; j++) 
            cout << freq_arr[i].ch;
    } 
}

void test_case()
{
    string s = "aaaabeebccccc";
    n = s.length();
    sortbyFrequency(s);

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
