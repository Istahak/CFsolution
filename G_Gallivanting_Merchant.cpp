#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        if (r - l + 1 >= k)
        {
            mp[0]++;
            mp[k]--;
        }
        else
        {
            int x = l % k;
            int y = r % k;
            if (x > y)
            {
                mp[0]++;
                mp[y + 1]--;
                mp[x]++;
                mp[k]--;
            }
            else
            {
                mp[x]++;
                mp[y + 1]--;
            }
        }
    }
    vector<int> v;
    for (auto [x, y] : mp)
        v.push_back(x);
    int ans = INT_MIN, cur = 0;
    for (auto i : v)
    {
        cur += mp[i];
        ans = max(ans, cur);
    }
    cout << ans << endl;

    return 0;
}