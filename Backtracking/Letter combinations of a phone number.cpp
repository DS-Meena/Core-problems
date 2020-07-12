#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n; 
string number = "24";
const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};

void printWords(int curr_digit, int n)
{   
    static string output; 
    if (curr_digit == n)
    {
        cout << output << endl;
        return; 
    }

    // try all cases 3 or 4 
    for (int i = 0; i < strlen(hashTable[number[curr_digit] - '0']); i++)
    {
        output.push_back(hashTable[number[curr_digit] - '0'][i]);
        printWords(curr_digit + 1, n); 
        output.pop_back();   // backtrack
        if (number[curr_digit] - '0' == 0 || number[curr_digit] - '0' == 1) 
            return;
    }
}

void test_case()
{   
    n = number.length();
    printWords(0, n);

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
