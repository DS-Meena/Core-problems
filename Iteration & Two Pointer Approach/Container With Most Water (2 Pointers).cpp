#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N = 100; 
const int mod = 1e9 + 7;

int n, m, k;

int MostWater(int height[])
{
    int maxArea = 0;
    int left = 0;
    int right = n - 1;
    
    while(left < right)
    {
        int minHeight = min(height[left], height[right]);
        int currArea = (right - left) * minHeight;
        maxArea = max(maxArea, currArea);

        if (height[left] < height[right]) 
            left++;
        else 
            right--;
    }

    return maxArea;
}

void test_case()
{
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};  n = sizeof(arr) / sizeof(arr[0]);
    cout << MostWater(arr);
        
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
