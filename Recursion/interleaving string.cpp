#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m;
/*
// 1st technique
bool caninterleave(char* a, char* b, char* c)
{
    if (!(*a || *b || *c)) 
        return true;
    if (*c == '\0') 
        return false;

    bool check1 = caninterleave(a + 1, b, c + 1);
    bool check2 = caninterleave(a, b + 1, c + 1);

    return ((*c == *a) && check1) || ((*c == *b) && check2); 
}

void test_case()
{
    char *a = "yx";
    char *b = "x";
    char *c = "yxx"; 
    m = strlen(a);
    n = strlen(b);
    if (caninterleave(a, b, c)) 
        cout << "YES";
    else 
         cout << "NO";

    cout << endl;
    return;
}
*/

// 2nd technique
int o;

bool checkinterleave(string s1, string s2, string s3, int i, int j, int k)
{  
    if (k >= o) 
       return true;  
    
    bool check1 = checkinterleave(s1, s2, s3, i + 1, j, k + 1);
    bool check2 = checkinterleave(s1, s2, s3, i, j + 1, k + 1);
    
    if ((s1[i] == s3[k]) && check1)
        return true;
    else if ((s2[j] == s3[k]) && check2)
        return true;
    else 
        return false;
    //return ((s1[i] == s3[k]) && check1) || ((s2[j] == s3[k]) && check2);
}

bool caninterleave(string s1, string s2, string s3)
{  
    n = s1.length();
    m = s2.length();
    o = s3.length();

    if (n + m != o) 
        return false;
    if (!(o || n || m)) 
        return true;
    return checkinterleave(s1, s2, s3, 0, 0, 0); 
}

void test_case()
{
    string s1 = "X", s2 = "YX", s3 = "XXY";
    if (caninterleave(s1, s2, s3)) 
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
