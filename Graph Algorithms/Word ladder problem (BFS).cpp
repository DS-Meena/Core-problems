#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

// bool isOneDiff(string a, string b)
// {
//     if (a.length() != b.length()) 
//         return false;
    
//     int diff = 0;
//     for (int i = 0; i < a.length(); i++) 
//     {
//         if (a[i] != b[i]) 
//             diff++;
//         if (diff > 1) 
//             return false;
//     }

//     if (diff == 1)  return true;
//     return false;
// }

int ladderLength(string beginWord, string endWord, set <string>& dict)
{
    if ( dict.find(endWord) == dict.end())
        return 0;

    int level = 0, wordlength = beginWord.size();

    queue <string> frontier;
    frontier.push(beginWord);

    while(! frontier.empty())
    {
        level++;
        int size = frontier.size();
        for (int i = 0; i < size; i++)
        {
            string currWord = frontier.front();
            frontier.pop();

            for (int pos = 0; pos < wordlength; pos++)
            {
                char orig_char = currWord[pos];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    currWord[pos] = c;
                    if (currWord == endWord) 
                        return level + 1;
                    if (dict.find(currWord) == dict.end())
                        continue;
                    dict.erase(currWord);
                    frontier.push(currWord);
                }
                currWord[pos] = orig_char;
            }

            // for (auto itr = dict.begin(); itr != dict.end(); itr++)
            // {
            //     if (isOneDiff(currWord, *itr)) 
            //     {
            //         if (*itr == endWord) 
            //             return level + 1;
            //         cout << *itr << " ";
            //         string w = *itr;
            //         frontier.push(w);
            //         dict.erase(w);
            //     }
            // }
        }    
    }

    return 0;
}

void test_case()
{
    set<string> dict = {"cool", "pool", "poll", "foil", "fail", "pole", "pope", "pale", "page", "sage", "sale", "fall"};
    // dict.insert("hit");
    // dict.insert("hot");
    // dict.insert("cot");
    // dict.insert("dog");
    // dict.insert("dot");
    // dict.insert("log");
    // dict.insert("cog");
    string start = "fool", end = "sage";
    cout << ladderLength(start, end, dict);

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
